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

def count_words(subreddit, word_list, key_dict={}, count=0, after=None):
    """
    recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords (case-insensitive,
    delimited by spaces. Javascript should count as javascript, but java should not.
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'user'}
    params = {"limit": 100, "after": after}
    key_dict = OrderedDict(key_dict)
    try:
        response = requests.get(url, headers=header, allow_redirects=False,
                                params=params).json()
    except ValueError:
        return
    """ adding all keywords to a dictionary """
    """ get data from the response """
    data = response.get('data')
    """ get the children """
    children = data.get('children')
    """ get the after """
    after = data.get('after')

    """ loop through the children """
    for child in children:
        """ parse the child data """
        post = (child.get('data')['title']).lower()
        """ split words in above request and loop through """
        for p in post:
            for word in word_list:
                word = word.lower()
                """ if the keyword is in the child title """
                if p == word:
                    """ if the keyword is in the dictionary """
                    if word in key_dict.keys():
                        """ add one to the count """
                        key_dict[word] += 1
                    else:
                        """ add the keyword to the dictionary """
                        key_dict[word] = 1
    """ if the after is not None """
    if after is not None:
        """ call the function again """
        return count_words(subreddit, word_list, key_dict, count, after)
    else:
        """ sort the dictionary """
        for item in sorted(key_dict, key=key_dict.get, reverse=True):
            print('{}: {}'.format(item, key_dict[item]))
