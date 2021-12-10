#!/usr/bin/python3
"""
recursive function that queries the Reddit API, parses the title of all
hot articles, and prints a sorted count of given keywords (case-insensitive,
delimited by spaces. Javascript should count as javascript, but java should not.

Prototype: def count_words(subreddit, word_list)
if word_list contains the same word (case-insensitive), the final count should
be the sum of each word's count.

Results should be printed in descending order, by the count, and if the count is
the same for separate keywords, they should be sorted alphabetically.

"""
import requests
import json
from collections import OrderedDict

def count_words(subreddit, word_list, after=None):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords (case-insensitive,
    delimited by spaces. Javascript should count as javascript, but java should not.
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'user'}
    params = {"show:": "all", "next": "next", "after": after}
    next_page = None
    try:
        response = requests.get(url, headers=header, allow_redirects=False,
                                params=params).json()
    except ValueError:
        return
    """ adding all keywords to a dictionary """
    word_dict = {}
    for word in word_list:
        if word.lower() not in word_dict:
            word_dict[word.lower()] = 0
        if word.lower() in word_dict:
            word_dict[word.lower()] += 1
    """ delimiate words in the titles """
    titles = []
    for post in response['data']['children']:
        titles.append(post['data']['title'].split())
    titles = [item for sublist in titles for item in sublist]
    """ adding keywords to the titles """
    for title in titles:
        if title.lower() in word_dict:
            word_dict[title.lower()] += 1
    """ next page """
    after = response.get("data").get("after")
    if after:
        count_words(subreddit, word_list, after)
    else:
        """ sorting the dictionary """
        word_dict = OrderedDict(sorted(word_dict.items(), key=lambda t: t[1],
                                       reverse=True))
        for word, count in word_dict.items():
            print("{}: {}".format(word, count))
        return
        