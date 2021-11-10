#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);
console.log(printCharacters(args));

function printCharacters(movieID) {
  var url = `https://swapi.co/api/films/${args}/`;
  request(url, function(error, response, body) {
    if (error) {
      console.log(error);
    } else {
      var data = JSON.parse(body);
      var characters = data.characters;
      for (var i = 0; i < characters.length; i++) {
        var character = characters[i];
        request(character, function(error, response, body) {
          if (error) {
            console.log(error);
          } else {
            var data = JSON.parse(body);
            console.log(data.name);
          }
        });
      }
    }
  });
}
