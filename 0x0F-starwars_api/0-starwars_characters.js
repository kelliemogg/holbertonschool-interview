#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);
console.log(printCharacters(args));

function printCharacters(movieID) {
  const url = `https://swapi.co/api/films/${args}/`;
  request(url, function(error, response, body) {
    if (error) {
      console.log(error);
    } else {
        const data = JSON.parse(body);
        const characters = data.characters;
        for (let i = 0; i < characters.length; i++) {
            const url = characters[i];
            request(url, function(error, response, body) {
            if (error) {
                console.log(error);
            } else {
                const data = JSON.parse(body);
                console.log(data.name);
            }
            });
        }
        }
    });
}
