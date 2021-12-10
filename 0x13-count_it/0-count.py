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

def count_words(subreddit, word_list):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords (case-insensitive,
    delimited by spaces. Javascript should count as javascript, but java should not.
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'user'}
    params = {"show:": "all", "next": "next", "after": None}
    try:
        response = requests.get(url, headers=header, allow_redirects=False,
                                params=params).json()
    except ValueError:
        return

    a_dict = {}
    for i in response['data']['children']:
        title = i['data']['title']
        for word in word_list:
            if word.lower() in title.lower():
                if word in a_dict:
                    a_dict[word] += 1
                else:
                    a_dict[word] = 1
    if a_dict:
        ordered_dict = OrderedDict(sorted(a_dict.items(), key=lambda t: (-t[1], t[0])))
        for key, value in sorted(a_dict.items(), key=lambda t: (-t[1], t[0])):
            if value != 0:
                print('{}: {}'.format(key, value))
    else:
        return
