
var timeout = 100;

function getElementsByClass(searchClass) {
	var classElements = new Array();
	var allElements = document.getElementsByTagName("*");
	var i, j;
	for (i = 0, j = 0; i < allElements.length; ++i) {
		if (allElements[i].className == searchClass) {
			classElements[j] = allElements[i];
			++j;
		}
	}
	return classElements;
}

function openCard(n) {
	var e = document.createEvent('MouseEvents');
	e.initEvent('click', false, true);
	var card = elements[n];
	card.dispatchEvent(e);
	return card.style.backgroundColor;
}

function yield() {
	while (!cards[i]) {
		++i;
		if (i >= elements.length) {
			return;
		}
	}
	while (true) {
		if (j >= elements.length) {
			return;
		}
		if (j <= i) {
			++j;
			continue;
		}
		if (index_to_color[i] && index_to_color[j] &&
				index_to_color[i] != index_to_color[j]) {
			++j;
			continue;
		}
		if (!cards[j]) {
			++j;
			continue;
		}
		break;
	}

	var a = openCard(i);
	var b = openCard(j);

	if (a == b) {
		cards[i] = 0;
		cards[j] = 0;
		j = i + 1;
	} else {
		index_to_color[i] = a;
		index_to_color[j] = b;
	}

	var t = setTimeout(yield, timeout);
}

var elements = getElementsByClass('card');
var cards = new Array();
var index_to_color = new Array();
var i, j;
for (i = 0; i < elements.length; ++i) {
	cards[i] = 1;
	index_to_color[i] = 0;
}
i = 0;
j = 1;

var t = setTimeout(yield, timeout);

