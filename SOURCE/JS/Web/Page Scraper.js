/**
 * Page Scraper: pulls all links and images from website
 * (npm install jsdom, use io.js to run)
 */
(function () {
"use strict";

var fs = require("fs"),
	readline = require('readline'),
	jsdom = require("jsdom");

var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

// Handler functions
var Handler = {};

Handler.jsdom = function (page) {
	return new Promise(function (resolve, reject) {
		jsdom.env({
			url: page,
			done: function (errors, window) {
				if (errors && errors.length > 0) {
					reject(errors);
				} else {
					resolve(window);
				}
			}
		});
	});
};

Handler.question = function (question) {
	return new Promise(function (resolve) {
		rl.question(question, function (response) {
			resolve(response);
		});
	});
};

// The main application
var Application = {
	links: [],
	images: [],
	page: undefined
};

// Filter duplicates from array
// Source: http://stackoverflow.com/questions/9229645/remove-duplicates-from-javascript-array#answer-9229821
Application.filter = function (a) {	
	var seen = {}, out = [], len = a.length, j = 0, i = 0;
	for(i = 0; i < len; i++) {
		var item = a[i];
		if(seen[item] !== 1) {
			seen[item] = 1;
			out[j++] = item;
		}
	}
	return out;
};

Application.main = function () {
	var self = this;
	
	console.log("------------------------");
	console.log("PAGE SCRAPER");
	console.log("------------------------");

	Handler.question("Enter page to pull: ").then(function (result) {
		self.page = result;
		self.pullPage();
	});
};

Application.pullPage = function () {
	var self = this;
	
	Handler.jsdom(self.page).then(function (window) {
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
		
		// Disallow duplicates
		self.links = self.filter(self.links);
		self.images = self.filter(self.images);
		
		console.log("Page \"" + self.page + "\" pulled. (" + self.links.length + " links and " + self.images.length + " images)");
		self.scrapped();
		
		window.close();
	}).catch(function (reason) {
		console.log("\nErrors occurred:\n" + reason.join("\n") + "\n");
		process.exit();
	});
};
	
Application.scrapped = function () {
	var self = this;
	
	console.log("\nOptions");
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
			case "4":
				process.exit();
			break;
			default:
				console.log("Choose one of the four.");
			break;
		}
		
		self.scrapped();
	});
};

Application.viewLinks = function () {
	console.log(this.links.join("\n"));
	
	console.log("------------------------");
	console.log("(Showed " + this.links.length + " links)");
};

Application.viewImages = function () {
	console.log(this.images.join("\n"));
	
	console.log("------------------------");
	console.log("(Showed " + this.images.length + " images)");
};

Application.saveToFile = function () {
	var self = this;
	console.log();
	
	rl.question("Enter file name: ", function (p) {
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
};

Application.main();
  
})();