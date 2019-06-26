#include <iostream>

using namespace std;

const string str[] = {
    "Lorem",       "ipsum",      "dolor",      "sit",          "amet,",
    "consectetur", "adipiscing", "elit.",      "Donec",        "quis",
    "lectus",      "sit",        "amet",       "ante",         "suscipit",
    "tempor.",     "Aenean",     "dapibus",    "finibus",      "tortor",
    "vitae",       "facilisis.", "Nulla",      "facilisi.",    "Donec",
    "suscipit",    "ante",       "a",          "sapien",       "gravida",
    "eleifend.",   "Curabitur",  "in",         "lectus",       "ut",
    "enim",        "semper",     "venenatis.", "Aenean",       "elit",
    "nibh,",       "hendrerit",  "nec",        "nunc",         "in,",
    "dictum",      "cursus",     "dolor.",     "Aenean",       "eget",
    "lectus",      "risus.",     "Cras",       "sollicitudin", "quam",
    "vitae",       "augue",      "mollis",     "bibendum.",    "Aliquam",
    "euismod",     "vulputate",  "dolor",      "at",           "tristique.",
    "Praesent",    "elementum",  "pretium",    "velit",        "non",
    "interdum.",   "Nunc",       "posuere",    "faucibus",     "magna",
    "id",          "pretium.",   "Maecenas",   "congue,",      "velit",
    "eget",        "semper",     "porttitor,", "tellus",       "tortor",
    "porttitor",   "dui,",       "tristique",  "lobortis",     "quam",
    "sem",         "ac",         "odio."};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int s, e;
  cin >> s >> e;

  for (int i = s; i <= e; ++i) {
    cout << str[i - 1] << (i == e ? "\n" : " ");
  }
}
