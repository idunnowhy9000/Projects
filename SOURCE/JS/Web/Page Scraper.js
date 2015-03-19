/**
 * Page Scraper: pulls all links and images from website
 * (npm install jsdom, use io.js to run)
 */
"use strict";

var fs = require("fs"),
	http = require("http"),
	readline = require('readline'),
	jsdom = require("jsdom");

var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

// Utilities
var NOOP = function () {};

// Handler functions
var Handler = {};

Handler.question = function (ask) {
	return new Promise(function (resolve, reject) {
		rl.question(ask, function (p) {
			resolve(p);
		});
	});
};

Handler.jsdom = function (page) {
	return new Promise(function (resolve, reject) {
		jsdom.env({
			url: page,
			done: resolve
		});
	});
}

// The main application
var Application = function () {
	this.links = [];
	this.images = [];
	this.page = undefined;
}

Application.prototype.main = function () {
	var self = this;
	
	console.log("------------------------");
	console.log("PAGE SCRAPER");
	console.log("------------------------");

	Handler.question("Enter page to pull: ").then(function (result) {
		self.page = p;
		self.pullPage();
	});
}

Application.prototype.pullPage = function () {
	var self = this;
	
	Handler.jsdom(self.page).then(function (errors, window) {
		var document = window.document;
			
		// Search for all "a" elements
		var aList = document.getElementsByTagName("a");
		Array.prototype.forEach.call(aList, function (elem) {
			if (typeof elem.href === 'string' && self.links.indexOf(elem.href) < 0) {
				self.links.push(elem.href);
			}
		});
		
		// Search for all "img" elements
		var imgList = document.getElementsByTagName("img");
		Array.prototype.forEach.call(imgList, function (elem) {
			if (typeof elem.src === 'string' && self.images.indexOf(elem.src) < 0) {
				self.images.push(elem.src);
			}
		});
		
		window.close();
	}).then(function () {
		self.scrapped();
	});
}
	
Application.prototype.scrapped = function () {
	var self = this;
	
	console.log("Page \"" + this.page + "\" pulled. (" + this.links.length + " links and " + this.images.length + " images)");
	
	console.log();
	console.log("Options");
	console.log("1: View all links");
	console.log("2: View all images");
	console.log("3: Save to file");
	console.log("4: Exit");
	
	Handler.question("> ").then(function (key) {
		switch (key) {
			case "1":
				self.viewLinks();
			break;
			case "2":
				self.viewImages();
			break;
			case "3":
				self.saveToFile();
				return;
			break;
			case "4":
				process.exit();
			break;
			default:
				console.log("Choose one of the four.");
			break;
		}
		
		self.scrapped();
	});
}

Application.prototype.viewLinks = function () {
	console.log(this.links.join("\n"));
	
	console.log("------------------------");
	console.log("(Showed " + this.links.length + " links)");
}

Application.prototype.viewImages = function () {
	console.log(this.images.join("\n"));
	
	console.log("------------------------");
	console.log("(Showed " + this.images.length + " images)");
}

Application.prototype.saveToFile = function () {
	var self = this;
	console.log();
	
	Handler.question("Enter file name: ").then(function (p) {
		if (!p.length) p = "page.txt";
		
		var data = "";
		data += "------------------------\n";
		data += "LINKS\n";
		data += "------------------------\n";
		data += self.links.join("\n");
		data += "\n\n";
		data += "------------------------\n";
		data += "IMAGES\n";
		data += "------------------------\n";
		data += self.images.join("\n");
		
		fs.writeFile(p, data, function (err) {
			if (err) throw err;
			console.log("Links and images has been saved to " + p);
			
			self.scrapped();
		});
	});
}

var app = new Application();
app.main();