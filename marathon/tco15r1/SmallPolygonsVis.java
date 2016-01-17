import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.util.*;
import java.security.*;
import javax.swing.*;

// ------------- class Point ------------------------------
class Pnt {
    public int x,y;
    public Pnt() {};
    public Pnt(int x1, int y1) {
        x = x1;
        y = y1;
    }
    public boolean equals(Pnt other) {
        return (x == other.x && y == other.y);
    }
}

// ------------- class G2D --------------------------------
class G2D {
    public static Pnt substr(Pnt p1, Pnt p2) {
        return new Pnt(p1.x - p2.x, p1.y - p2.y);
    }
    public static double norm(Pnt p) {
        return Math.sqrt(p.x * p.x + p.y * p.y);
    }
    public static int norm2(Pnt p) {
        return (p.x * p.x + p.y * p.y);
    }
    public static int dot(Pnt p1, Pnt p2) {
        return p1.x * p2.x + p1.y * p2.y;
    }
    public static int cross(Pnt p1, Pnt p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }
    public static double dist(Pnt p1, Pnt p2) {
        return norm(substr(p1, p2));
    }
    public static int dist2(Pnt p1, Pnt p2) {
        return norm2(substr(p1, p2));
    }
}

// ------------- class Edge ------------------------------
class Edge {
    public Pnt p1, p2, vect;    //vector p1 -> p2
    public double norm;
    public Edge() {};
    public Edge(Pnt p1n, Pnt p2n) {
        p1 = p1n;
        p2 = p2n;
        vect = G2D.substr(p2, p1);
        norm = G2D.norm(vect);
    }
    public Edge(int x1, int y1, int x2, int y2) {
        p1 = new Pnt(x1, y1);
        p2 = new Pnt(x2, y2);
        vect = G2D.substr(p2, p1);
        norm = G2D.norm(vect);
    }
    boolean eq(double a, double b){
      return Math.abs(a-b) < 1e-9;
    }
    // ---------------------------------------------------
    public boolean intersect(Edge other) {
        //do edges "this" and "other" intersect?
        if (Math.min(p1.x,p2.x) > Math.max(other.p1.x,other.p2.x)) return false;
        if (Math.max(p1.x,p2.x) < Math.min(other.p1.x,other.p2.x)) return false;
        if (Math.min(p1.y,p2.y) > Math.max(other.p1.y,other.p2.y)) return false;
        if (Math.max(p1.y,p2.y) < Math.min(other.p1.y,other.p2.y)) return false;

        int den = other.vect.y*vect.x-other.vect.x*vect.y;
        int num1 = other.vect.x*(p1.y-other.p1.y)-other.vect.y*(p1.x-other.p1.x);
        int num2 =       vect.x*(p1.y-other.p1.y)-      vect.y*(p1.x-other.p1.x);

        //parallel edges
        if (den==0)
        {   if (Math.min(other.dist2(this),dist2(other)) > 0)
                return false;
            //on the same line - "not intersect" only if one of the vertices is common,
            //and the other doesn't belong to the line
            if ((this.p1==other.p1 && eq(G2D.dist(this.p2, other.p2) , this.norm + other.norm)) || 
                (this.p1==other.p2 && eq(G2D.dist(this.p2, other.p1) , this.norm + other.norm)) ||
                (this.p2==other.p1 && eq(G2D.dist(this.p1, other.p2) , this.norm + other.norm)) ||
                (this.p2==other.p2 && eq(G2D.dist(this.p1, other.p1) , this.norm + other.norm)))
                return false;
            return true;
        }

        //common vertices
        if (this.p1==other.p1 || this.p1==other.p2 || this.p2==other.p1 || this.p2==other.p2)
            return false;

        double u1 = num1*1./den;
        double u2 = num2*1./den;
        if (u1<0 || u1>1 || u2<0 || u2>1)
            return false;
        return true;
    }
    // ---------------------------------------------------
    public double dist(Pnt p) {
        //distance from p to the edge
        if (G2D.dot(vect, G2D.substr(p, p1))<=0)
            return G2D.dist(p, p1);         //from p to p1
        if (G2D.dot(vect, G2D.substr(p, p2))>=0)
            return G2D.dist(p, p2);         //from p to p2
        //distance to the line itself
        return Math.abs(-vect.y*p.x+vect.x*p.y+p1.x*p2.y-p1.y*p2.x)/norm;
    }
    // ---------------------------------------------------
    public double dist2(Edge other) {
        //distance from the closest of the endpoints of "other" to "this"
        return Math.min(dist(other.p1), dist(other.p2));
    }
}

// ------------- class SmallPolygon itself --------------
public class SmallPolygonsVis {
    final int SZ = 700;             // field size
    int NP, N, Npoly;               // number of points given, max number of polygons and number of polygons selected
    Pnt[] p;                        // coordinates of points (fixed)
    int[] pointsPar;                // coordinates of points (as an array parameter)
    int[][] polys;                  // indices of points which form polygons
    int[] polysVert;                // number of vertices in each poly
    boolean valid[];
    int[] used;                     // which poly uses this point?
    HashSet<Integer> badEdges = new HashSet<>(); // intersecting edges
    // ---------------------------------------------------
    void generate(String seed) {
      try {
        SecureRandom rnd = SecureRandom.getInstance("SHA1PRNG");
        rnd.setSeed(Long.parseLong(seed));
        // generate points by sampling each coordinate uniformly, without duplicates
        int i, j, k;
        // number of points
        if (seed.equals("1"))
            NP = 10;
        else {
            int testSize = rnd.nextInt(3);
            if (testSize == 0) NP = rnd.nextInt(80) + 20;
            else if (testSize == 1) NP = rnd.nextInt(400) + 100;
            else NP = rnd.nextInt(1001) + 500;
        }
        System.out.println("NP = " + NP);
        p = new Pnt[NP];

        // generate the points
        boolean ok;
        for (i = 0; i < NP; ++i)
        {
            do {
                p[i] = new Pnt(rnd.nextInt(SZ), rnd.nextInt(SZ));
                ok = true;
                for (j = 0; j < i && ok; ++j)
                    if (p[i].equals(p[j]))
                        ok = false; 
            }
            while (!ok);
        }

        // convert points to parameter array
        pointsPar = new int[2 * NP];
        for (i = 0; i < NP; ++i) {
            pointsPar[2 * i] = p[i].x;
            pointsPar[2 * i + 1] = p[i].y;
        }

        if (manual) {
            // and to coordToPoint
            coordToPoint = new int[SZ][SZ];
            for (i = 0; i < SZ; ++i)
                Arrays.fill(coordToPoint[i], -1);
            int x, y;
            for (i = 0; i < NP; ++i)
                for (j = -1; j <= 1; ++j)
                for (k = -1; k <= 1; ++k)
                {
                    x = p[i].x + j;
                    y = p[i].y + k;
                    if (x >= 0 && x < SZ && y >= 0 && y < SZ)
                        coordToPoint[x][y] = i;
                }
        }

        N = rnd.nextInt(19) + 2;
        if (seed.equals("1"))
            N = 3;
        System.out.println("N = " + N);
      }
      catch (Exception e) { 
        addFatalError("An exception occurred while generating test case.");
        e.printStackTrace(); 
      }
    }
    // ---------------------------------------------------
    String validatePoly(int[] poly, int n) {
        // check that the polygon satisfies all individual conditions
        if (n < 3)
            return "a polygon must have at least 3 vertices.";

        // simple polygon: no self-intersections except in common vertices of edges
        for (int i = 0; i < n; ++i) 
        for (int j = i + 1; j < n; ++j) {
            // check intersection of i..i+1 and j..j+1
            Edge e1 = new Edge(p[poly[i]], p[poly[(i + 1) % n]]);
            Edge e2 = new Edge(p[poly[j]], p[poly[(j + 1) % n]]);
            if (e1.intersect(e2)) {
                badEdges.add(poly[i]);
                badEdges.add(poly[j]);
                return "edges "+poly[i]+"-"+poly[(i+1)%n]+" and "+poly[j]+"-"+poly[(j+1)%n]+" intersect";
            }
        }
        return "";
    }
    // ---------------------------------------------------
    double area(int[] poly, int n) {
        // trapezium method
        double s = 0;
        for (int i = 0; i < n; i++)
            s += (p[poly[(i + 1) % n]].y + p[poly[i]].y) * (p[poly[(i + 1) % n]].x - p[poly[i]].x) / 2.0;
        return Math.abs(s);
    }
    // ---------------------------------------------------
    double calcScore() {
        // calculate the score of current set of polygons (sum of areas), including full validity check
        // will be called from interactive editing to show the results of changes
        // 1. there are at most N polygons
        if (Npoly > N) {
            addFatalError("You can have at most " + N + " polygons.");
            return 0;
        }

        // 2. each point is used by one of polygons (no polygons using same point checked earlier)
        for (int i = 0; i < used.length; ++i) 
            if (used[i] == -2)
            {
                addFatalError("Point " + i + " is not used in any polygon.");
                return 0;
            }

        // 3. each polygon is valid on its own
        for (int i = 0; i < polys.length; ++i)
        {
            if (manual && polysVert[i] == 0)
            {
                // polysVert[i] = 0 in manual mode means this is a deleted polygon; check only non-deleted ones
                continue;
            }
            if (!valid[i] && strict)
            {
                addFatalError("Polygon " + i + " is not valid: " + validatePoly(polys[i], polysVert[i]));
                return 0;
            }
        }

        // 4. no two polygons intersect
        // for an intersection to be detected, polygons have to have at least 2 vertices, so deleted polygons in manual mode have no effect
        for (int i = 0; i < polys.length; ++i)
        for (int j = 0; j < polysVert[i]; ++j) {
            for (int k = i + 1; k < polys.length; ++k)
            for (int l = 0; l < polysVert[k]; ++l) {
                // check intersection of edge j..j+1 of polygon i and edge l..l+1 of polygon k
                Edge e1 = new Edge(p[polys[i][j]], p[polys[i][(j + 1) % polysVert[i]]]);
                Edge e2 = new Edge(p[polys[k][l]], p[polys[k][(l + 1) % polysVert[k]]]);
                if (e1.intersect(e2)) {
                    badEdges.add(polys[i][j]);
                    badEdges.add(polys[k][l]);
                    addFatalError("edges "+polys[i][j]+"-"+polys[i][(j + 1) % polysVert[i]]+" and "+polys[k][l]+"-"+polys[k][(l + 1) % polysVert[k]]+" intersect");
                    return 0;
                }
            }
        }
        
        // now, if all are valid, score is always non-0
        double score = 0;
        for (int i = 0; i < polys.length; ++i)
            score += area(polys[i], polysVert[i]);
        return score;
    }
    // ---------------------------------------------------
    public double runTest(String seed) {
      try {
        int i, j;
        generate(seed);
        //init variables
        used = new int[NP];
        Arrays.fill(used, -2);
        badEdges.clear();

        // allow combining two modes - program output and manual correction
        if (proc != null) {
            // get the return and parse it into the polygons
            String[] ret;
            try { ret = choosePolygons(pointsPar, N); }
            catch (Exception e) {
                addFatalError("Failed to get result from choosePolygons.");
                return 0;
            }
            // each string represents one polygon: number of vertices, indices of the vertices in original array
            Npoly = ret.length;
            // if there will be manual play, add slots for more polygons for future
            int n = Npoly;
            if (manual)
                n = Math.max(n, N);
            polys = new int[n][];
            polysVert = new int[n];
            valid = new boolean[n];
            for (i = 0; i < Npoly; ++i) {
                // parse the string into the polygon
                try {
                    if (debug) System.out.println(ret[i]);
                    String[] st = ret[i].split(" ");
                    int nv = st.length;        // number of vertices in this polygon
                    // if there will be manual play, add slots for more vertices for each polygon
                    if (manual)
                        polys[i] = new int[Math.max(nv, NP)];
                    else 
                        polys[i] = new int[nv];
                    polysVert[i] = nv;
                    for (j = 0; j < nv; ++j) {
                        polys[i][j] = Integer.parseInt(st[j]);
                        // check whether this point already was used
                        if (used[polys[i][j]] > -2) {
                            addFatalError("Polygon " + i + " reuses point " + polys[i][j] + ".");
                            return 0;
                        }
                        else
                            used[polys[i][j]] = i;
                    }
                } catch (Exception e) {
                    addFatalError("Polygon " + i + " parses with errors.");
                    return 0;
                }
                // validate this polygon
                String valRes = validatePoly(polys[i], polysVert[i]);
                if (valRes.length() != 0) {
                    addFatalError("Polygon " + i + " is invalid: " + valRes);
                    valid[i] = false;
                }
                else
                    valid[i] = true;
            }
        }
        else {
            // no polygons initially
            Npoly = 0;
            polys = new int[N][];
            polysVert = new int[N];
            valid = new boolean[N];
        }

        if (vis) {
            // draw the image
            jf.setSize(SZX+17,SZY+37);
            jf.setVisible(true);
            draw();
        }

        if (manual) {
            ready = false;
            Pcur = new int[2000];
            Ncur = 0;
            // wait for the result of manual polygons adjustments - validation will be done there
            while (!ready)
                try { Thread.sleep(1000);}
                catch (Exception e) { e.printStackTrace(); } 
        }

        return calcScore();
      }
      catch (Exception e) { 
        addFatalError("An exception occurred while trying to process your program's results.");
        e.printStackTrace(); 
        return 0.0;
      }
    }
// ------------- visualization part ----------------------
    static String exec;
    static boolean vis, manual, debug, strict;
    static Process proc;
    JFrame jf;
    Vis v;
    InputStream is;
    OutputStream os;
    BufferedReader br;
    // problem-specific drawing params
    final int SZX = SZ+2+100,SZY=SZ+2;
    volatile boolean ready;
    volatile int Ncur;
    volatile int[] Pcur;
    int[][] coordToPoint;
    // ---------------------------------------------------
    String[] choosePolygons(int[] points, int N) throws IOException
    {   // pass the params to the solution and get the return
        int i;
        StringBuffer sb = new StringBuffer();
        sb.append(points.length).append('\n');
        for (i = 0; i < points.length; ++i)
            sb.append(points[i]).append('\n');
        sb.append(N).append('\n');
        os.write(sb.toString().getBytes());
        os.flush();
        // get the return - an array of strings
        int nret = Integer.parseInt(br.readLine());
        System.out.println(nret);
        String[] ret = new String[nret];
        for (i = 0; i < nret; ++i)
            ret[i] = br.readLine();
        return ret;
    }
    // ---------------------------------------------------
    void draw() {
        if (!vis) return;
        v.repaint();
    }
    // ---------------------------------------------------
    public class Vis extends JPanel implements MouseListener, WindowListener {
        public void paint(Graphics g) {
          try {
           //do painting here
            int i,j,n;
            char[] ch;
            BufferedImage bi = new BufferedImage(SZX+10,SZY+10,BufferedImage.TYPE_INT_RGB);
            Graphics2D g2 = (Graphics2D)bi.getGraphics();
            //background
            g2.setColor(new Color(0xD3D3D3));
            g2.fillRect(0,0,SZX+10,SZY+10);
            g2.setColor(Color.WHITE);
            g2.fillRect(0,0,SZ+1,SZ+1);
            //frame
            g2.setColor(Color.BLACK);
            g2.drawRect(0,0,SZ+1,SZ+1);

            //sides
            for (i=0; i<polys.length; i++) {
                n = polysVert[i];
                if (valid[i]) {
                    float hue = (float)(i) / polys.length;
                    g2.setColor(Color.getHSBColor(hue, 0.9f, 1.0f));
                    int[] xPoints = new int[n];
                    int[] yPoints = new int[n];
                    for (j=0; j<n; j++) {
                        xPoints[j] = p[polys[i][j]].x;
                        yPoints[j] = (SZ-1-p[polys[i][j]].y);
                    }
                    g2.fillPolygon(xPoints, yPoints, n);
                }
                if (valid[i])
                    g2.setColor(Color.GREEN);
                else
                    g2.setColor(Color.RED);
                for (j=0; j<n; j++) {
                    g2.drawLine(p[polys[i][j]].x, (SZ-1-p[polys[i][j]].y), p[polys[i][(j+1)%n]].x, (SZ-1-p[polys[i][(j+1)%n]].y));
                }
                if (badEdges.size()>0) {
                    g2.setColor(Color.RED);
                    g2.setStroke(new BasicStroke(3));
                    for (j=0; j<n; j++) {
                        if (badEdges.contains(polys[i][j]))
                            g2.drawLine(p[polys[i][j]].x, (SZ-1-p[polys[i][j]].y), p[polys[i][(j+1)%n]].x, (SZ-1-p[polys[i][(j+1)%n]].y));
                    }
                    g2.setStroke(new BasicStroke(1));
                }
            }
            //draw current poly
            g2.setColor(new Color(0x6495ED));
            for (i=0; i<Ncur; i++) {
                g2.drawLine(p[Pcur[i]].x, (SZ-1-p[Pcur[i]].y), p[Pcur[(i+1)%Ncur]].x, (SZ-1-p[Pcur[(i+1)%Ncur]].y));
            }

            //"buttons"
            if (manual) {
                g2.setColor(Color.BLACK);
                ch = ("SUBMIT").toCharArray();
                g2.setFont(new Font("Arial",Font.BOLD,16));
                g2.drawChars(ch,0,ch.length,SZ+20,30);
                g2.drawRect(SZ+12,8,90,30);

                ch = ("ADD POLY").toCharArray();
                g2.setFont(new Font("Arial",Font.BOLD,14));
                g2.drawChars(ch,0,ch.length,SZ+18,109);
                g2.drawRect(SZ+12,88,90,30);

                ch = ("DEL POLY").toCharArray();
                g2.setFont(new Font("Arial",Font.BOLD,14));
                g2.drawChars(ch,0,ch.length,SZ+19,149);
                g2.drawRect(SZ+12,128,90,30);
            }

            //current score
            ch = (""+calcScore()).toCharArray();
            g2.setFont(new Font("Arial",Font.BOLD,14));
            g2.drawChars(ch,0,ch.length,SZ+10,200);

            //points with small digits near them
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setFont(new Font("Arial",Font.PLAIN,10));
            for (i=0; i<NP; i++)
            {   if (used[i]>-1) {
                    if (valid[used[i]])
                        g2.setColor(Color.GREEN);
                    else g2.setColor(Color.RED);
                }
                else {
                    if (used[i]==-1) {
                        //a special highlight for last point in the polygon
                        if (Pcur[Ncur-1]==i)
                            g2.setColor(new Color(0x6495ED));
                        else g2.setColor(new Color(0x000080));
                    }
                    else g2.setColor(Color.BLACK);
                }
                g2.fillOval(p[i].x-2, SZ-1-p[i].y-2,5,5);
                if (debug) {
	                g2.setColor(Color.BLACK);
                    ch = (i+"").toCharArray();
                    g2.drawChars(ch,0,ch.length, p[i].x+2, SZ-1-p[i].y-2);
                }
            }

            g.drawImage(bi,0,0,SZX+10,SZY+10,null);
      }
      catch (Exception e) { e.printStackTrace(); }
        }
        public Vis() {
            if (manual)
                addMouseListener(this);
            jf.addWindowListener(this);
        }
    // ---------------------------------------------------
        //MouseListener
        public void mouseClicked(MouseEvent e) {
            //identify the buttons or the click on the field
            int x = e.getX(), y = e.getY(), i, j;
            if (x>SZ) {
                //can be only mode modifiers
                if (y >= 8 && y <= 38) {
                    //"SUBMIT"
                    ready = true;
                }
                if (y >= 88 && y <= 118) {
                    //"ADD POLY"
                    String val = validatePoly(Pcur, Ncur);
                    if (val.length()!=0) {
                        System.out.println("Current polygon is invalid: "+val);
                    }
                    else {
                        //actually commit the polygon - find first slot with no poly in it and add it there
                        for (i=0; i<polys.length; i++)
                            if (polysVert[i]==0)
                                break;
                        if (i == polys.length) {
                            System.out.println("Can't have more than "+polys.length+" polygons.");
                        } else {
                            //put current poly to the slot
                            if (debug) System.out.println("Adding current polygon to slot "+i);
                            polysVert[i] = Ncur;
                            valid[i] = true;    //already verified
                            if (polys[i] == null || polys[i].length < Ncur)
                                polys[i] = new int[Ncur];
                            for (j=0; j<Ncur; j++) {
                                polys[i][j] = Pcur[j];
                                used[Pcur[j]] = i;
                            }
                            Ncur = 0;
                            Npoly++;
                        }
                    }
                }
                if (y >= 128 && y <= 158) {
                    //"DEL POLY"
                    //delete the currently selected poly (and unmark used points)
                    if (debug) System.out.println("Deleting current polygon");
                    for (i=0; i<Ncur; i++)
                        used[Pcur[i]] = -2;
                    Ncur = 0;
                }
                draw();
                return;
            }
            //now, the clicks weren't buttons - they were points' locations
            y = SZ-y-1;
            int indP = coordToPoint[x][y], indPoly;
            if (indP==-1)
                return;
            //now process the point
            indPoly = used[indP];

            //three scenarios: adding a point to current poly, removing it or choosing a poly to be edited
            if (Ncur == 0 && indPoly > -1) {
                //this polygon is moved to editing: delete it from the list and free its parameters
                if (debug) System.out.println("Editing polygon "+indPoly);
                Ncur = polysVert[indPoly];
                polysVert[indPoly] = 0;
                valid[indPoly] = false;
                for (i=0; i<Ncur; i++) {
                    Pcur[i] = polys[indPoly][i];
                    polys[indPoly][i] = -1;
                    used[Pcur[i]] = -1;
                }
                Npoly--;
            } else
                if (Ncur > 0 && indPoly == -1 && Pcur[Ncur-1]==indP) {
                    //this point is last in the polygon - remove it
                    if (debug) System.out.println("Removing point "+indP+" from current polygon");
                    Ncur --;
                    used[indP] = -2;
                    Pcur[Ncur] = -2;
                } else
                    if (indPoly == -2) {
                        if (debug) System.out.println("Adding point "+indP+" to current polygon");
                        Pcur[Ncur] = indP;
                        Ncur++;
                        used[indP] = -1;
                    } else {
                        if (debug) System.out.println("Invalid action");
                       return;
                    }

            draw();
        }
        public void mousePressed(MouseEvent e) { }
        public void mouseReleased(MouseEvent e) { }
        public void mouseEntered(MouseEvent e) { }
        public void mouseExited(MouseEvent e) { }
        //WindowListener
        public void windowClosing(WindowEvent e) { 
            if(proc != null)
                try { proc.destroy(); } 
                catch (Exception ex) { ex.printStackTrace(); }
            System.exit(0); 
        }
        public void windowActivated(WindowEvent e) { }
        public void windowDeactivated(WindowEvent e) { }
        public void windowOpened(WindowEvent e) { }
        public void windowClosed(WindowEvent e) { }
        public void windowIconified(WindowEvent e) { }
        public void windowDeiconified(WindowEvent e) { }
    }
    // ---------------------------------------------------
    public SmallPolygonsVis(String seed) {
        //interface for runTest
        if (vis)
        {   jf = new JFrame();
            v = new Vis();
            jf.getContentPane().add(v);
        }
        if (exec != null) {
            try {
                Runtime rt = Runtime.getRuntime();
                proc = rt.exec(exec);
                os = proc.getOutputStream();
                is = proc.getInputStream();
                br = new BufferedReader(new InputStreamReader(is));
                new ErrorReader(proc.getErrorStream()).start();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("Score = "+runTest(seed));
        if (proc != null)
            try { proc.destroy(); } 
            catch (Exception e) { e.printStackTrace(); }
    }
    // ---------------------------------------------------
    public static void main(String[] args) {
        String seed = "1";
        vis = false;
        manual = false;
        strict = true;
        for (int i = 0; i<args.length; i++)
        {   if (args[i].equals("-seed"))
                seed = args[++i];
            if (args[i].equals("-exec"))
                exec = args[++i];
            if (args[i].equals("-vis"))
                vis = true;
            if (args[i].equals("-manual"))
                manual = true;
            if (args[i].equals("-debug"))
                debug = true;
            if (args[i].equals("-nostrict"))
                strict = false;
        }
        if (manual)
            vis = true;
        SmallPolygonsVis f = new SmallPolygonsVis(seed);
    }
    // ---------------------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
    }
}

class ErrorReader extends Thread{
    InputStream error;
    public ErrorReader(InputStream is) {
        error = is;
    }
    public void run() {
        try {
            byte[] ch = new byte[50000];
            int read;
            while ((read = error.read(ch)) > 0)
            {   String s = new String(ch,0,read);
                System.out.print(s);
                System.out.flush();
            }
        } catch(Exception e) { }
    }
}
