#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);
const url = `https://swapi.co/api/films/${args}/`;


request(url, function (error, response, body) {
    if (error) {
        console.log(error);
    }
    const characters = JSON.parse(body).characters;

    characters.forEach(function (character) {
        request(character, function (error, response, body) {
            if (error) {
                console.log(error);
            }
            const charName = JSON.parse(body).name;
            const listCharacters = {};
            listCharacters[charName] = character;
            if (Object.values(listCharacters).length === characters.length) {
                characters.forEach(function (character) {
                    console.log(listCharacters[character]);
                });
            }
        });
    });
});
