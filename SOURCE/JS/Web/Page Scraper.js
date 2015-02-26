"use strict";

var fs = require("fs"),
	http = require("http"),
	readline = require('readline'),
	jsdom = require("jsdom");

var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

var Application = {
	links: [],
	page: "",
	images: [],
	
	main: function () {
		var self = this;
		
		console.log("------------------------");
		console.log("PAGE SCRAPER");
		console.log("------------------------");

		rl.question("Enter page to pull: ", function (p) {
			self.page = p;
			self.pullPage();
			
			rl.close();
		});
	},
	pullPage: function () {
		var self = this;
		
		console.log("Pulling page \"" + self.page + "\"...");
	
		jsdom.env({
			url: self.page,
			done: function (errors, window) {
				var document = window.document;
				
				// Search for all "a" elements
				var aList = document.getElementsByTagName("a");
				Array.prototype.forEach.call(aList, function (elem) {
					if (elem.href) self.links.push(elem.href);
				});
				
				// Search for all "img" elements
				var imgList = document.getElementsByTagName("img");
				Array.prototype.forEach.call(imgList, function (elem) {
					if (elem.src) self.images.push(elem.src);
				});
				
				self.scraped();
				window.close();
			}
		});
	},
}

Application.main();