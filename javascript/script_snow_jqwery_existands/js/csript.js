$.ItIsSnow = function (speed, count, breeze) {

	$("html,body").css("overflow","hidden");
	
	function Snow(elem, speed, img, marginLeft, breeze, stepInterval) {
		this.speed = speed || 10;
		this.timer;
		this.img = img;
		this.elem = elem;
		this.breeze = breeze;
		this.marginTop = -50;
		this.marginLeft = marginLeft;
		this.toFall = function () {

			let heigth = $(window).height();
			if (this.marginTop > heigth) {
				this.marginTop = 0;
				let min = 0;
				let max = $(window).width();
				let marginNew = Math.random() * (max - min) + min;
				this.marginLeft = marginNew;
				this.elem.css("left", marginNew);
			}

			if (this.elem.css("left") > $(window).width()) {
				this.elem.css("left", 0);
				this.marginLeft = 0;
			}

			if (this.breeze) {
				let leftMargin = this.elem.css("left");
				this.elem.css("left", 1.001 * (parseFloat(leftMargin)));
			}

			this.marginTop = this.marginTop + this.speed;
			this.elem.css("top", this.marginTop);
		}.bind(this);

		this.startTimer = function () {
			this.timer = setInterval(this.toFall, this.stepInterval);
		}.bind(this);
	}

	let snowflakes = [];

	for (let i = 0; i < count; i++) {
		let img = $("<img></img>");
		let minSize = 15;
		let maxSize = 50;

		let sizeImg = Math.random() * (maxSize - minSize) + minSize;
		img.css("top",-sizeImg);

		let imgSnow = "https://vignette.wikia.nocookie.net/transformice/images/2/27/Snowflake.png/revision/latest/scale-to-width-down/480?cb=20141218233410";
		img.attr("alt", "snow").css({
			position: "absolute",
			height: sizeImg + "px"
		});
		img.attr("src", imgSnow);

		img.appendTo($("body"));

		let minInterval = 2000;
		let maxInterval = 5000;

		let stepInterval = Math.random() * (maxInterval - minInterval) + minInterval;

		let min = 0;
		let max = $(window).width();

		let marginLeftSnow = Math.random() * (max - min) + min;
		let snowflake = new Snow(img, speed, imgSnow, marginLeftSnow, breeze, stepInterval);

		img.css("left", marginLeftSnow);
		snowflakes.push(snowflake);

		for (let i = 0; i < snowflakes.length; i++) {
			snowflakes[i].startTimer();
		}
	}
};
