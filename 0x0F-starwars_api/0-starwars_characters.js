#!/usr/bin/node

const request = require('request');
const args = process.argv;
const url = `https://swapi-api.hbtn.io/api/films/${args[2]}/`;


request(url, function (error, response, body) {
    if (error) {
        console.log(error);
    }
    const characters = JSON.parse(body).characters;
    const listCharacters = {};

    characters.forEach(function (character) {
        request(character, function (error, response, body) {
            if (error) {
                console.log(error);
            }
            const charName = JSON.parse(body).name;
            listCharacters[character] = charName;
            if (Object.values(listCharacters).length === characters.length) {
                characters.forEach(character => {
                    console.log(listCharacters[character]);
                });
            }
        });
    });
});
