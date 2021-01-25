#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using std::cout;            using std::endl;
using std::string;          using std::unordered_set;

using std::search;          using std::advance;
using std::all_of;
/*
 * Note that you have to pass in the file as a single string
 * into the findWikiLinks function!
 * So we have to turn the passed-in file into a single string...
 * does that sound familiar at all?
 */
unordered_set<string> findWikiLinks(const string& page_html) {
    // TODO: delete this return statement and implement the
    //       function!
    // return {};

    unordered_set<string> wiki_links;    
    const string LINK_HEAD = "href=";
    const size_t STEP = LINK_HEAD.size() + 1;

    const char HASH = '#', COLON = ':';
    string cur_link;
    auto iter_search = search(page_html.begin(), page_html.end(), LINK_HEAD.begin(), LINK_HEAD.end());

    while (iter_search != page_html.end()) {
        iter_search += STEP;
        auto iter_find = std::find(iter_search, page_html.end(), '"');
        if (iter_find != page_html.end()) {
            cur_link = string(iter_search, iter_find);
            string tmp = cur_link.substr(0, 6);
            if (tmp == "/wiki/" && all_of(cur_link.begin(), cur_link.end(), [](const char c) -> bool {
                    return c != HASH && c != COLON; })) {
                wiki_links.insert(cur_link.substr(6));
            }
        }
        iter_search = search(iter_search, page_html.end(), LINK_HEAD.begin(), LINK_HEAD.end());
    }

    return wiki_links;
}


int main() {
    /* Note if your file reading isn't working, please go to the
     * projects tab on the panel on the left, and in the run section,
     * uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */

    cout << "Enter a file name: ";
    string filename;
    getline(std::cin, filename);
    string page_html;

    // TODO: Create a filestream from the filename, and convert it into
    //       a single string of data called page_html (declared above)

    // Write code here
    ::std::ifstream fs(filename, std::ifstream::in);
    ::std::stringstream ss; // use stringstream to read entire file
    ss << fs.rdbuf();
    page_html = ss.str();

    unordered_set<string> validLinks = findWikiLinks(page_html);

    // TODO: Print out the validLinks set above.
    //       You can print it out in any format; this is just for you
    //       to be able to compare your results with the [output] results
    //       under the /res folder.

    // Write code here
    for (const auto& L: validLinks) {
        cout << L << endl;
    }

    return 0;
}
