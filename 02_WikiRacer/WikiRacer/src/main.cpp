#include <iostream>     // for cout, cin
#include <fstream>      // for ifstream
#include <sstream>      // for stringstream
#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;

/*
 * This is the function you will be implementing. It takes
 * two string representing the names of a start_page and
 * end_page and is supposed to return a ladder, represented
 * as a vector<string>, of links that can be followed from
 * start_page to get to the end_page.
 *
 * For the purposes of this algorithm, the "name" of a Wikipedia
 * page is what shows at the end of the URL when you visit that page
 * in your web browser. For ex. the name of the Stanford University
 * Wikipedia page is "Stanford_University" since the URL that shows
 * in your browser when you visit this page is:
 *
 *       https://en.wikipedia.org/wiki/Stanford_University
 */
vector<string> findWikiLadder(const string& start_page, const string& end_page) {
    // TODO: 1. Once your file reading is working, replace the below
    //          return statement with "return {};".
    //       2. Make sure that you've copied over your findWikiLinks method
    //          from Part A into wikiscraper.cpp.
    //       3. Finally, implement this function per Part B in the handout!
    //
    //                Best of luck!
    // return {"File reading works!", start_page, end_page};

    WikiScraper scraper;
    auto target_set = scraper.getLinkSet(end_page); // set of links

    std::vector<string> ladder;
    ladder.push_back(start_page);

    // heuristic function, compare similarity with target set to determine the priority
    auto cmp_func = [&](const vector<string>& a, const vector<string>& b) -> bool {

        auto a_set = scraper.getLinkSet(a.back());
        vector<string> a_common;
        std::set_intersection(a_set.begin(), a_set.end(), target_set.begin(), target_set.end(), std::back_inserter(a_common));

        auto b_set = scraper.getLinkSet(b.back());
        vector<string> b_common;
        std::set_intersection(b_set.begin(), b_set.end(), target_set.begin(), target_set.end(), std::back_inserter(b_common));

        return a_common.size() < b_common.size();
    };

    priority_queue<vector<string>, vector<vector<string>>, decltype(cmp_func)> pq(cmp_func);
    pq.push(ladder);

    while (!pq.empty()) {
        ladder = pq.top();
        pq.pop();

        auto links = scraper.getLinkSet(ladder.back());

        if (links.find(end_page) != links.end()) {
            ladder.push_back(end_page);
            return ladder;
        } else {
            for (const auto& link: links) {
                auto new_ladder = ladder;
                new_ladder.push_back(link);
                pq.push(new_ladder);
            }
        }
    }

    return {};
}

int main() {
    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    // TODO: Create a filestream from the filename.
    //       For each pair {start_page, end_page} in the input file,
    //       retrieve the result of findWikiLadder(start_page, end_page)
    //       and append that vector to outputLadders.

    // Write code here
    ifstream fin(filename, std::ifstream::in);
    string start_page, end_page;
    while (fin >> start_page >> end_page) {
        outputLadders.push_back(findWikiLadder(start_page, end_page));
    }

    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    for (auto& ladder : outputLadders) {
        if(ladder.empty()) {
            cout << "No ladder found!" << endl;
        } else {
            cout << "Ladder found:" << endl;
            cout << "\t" << "{";

            std::copy(ladder.begin(), ladder.end() - 1,
                      std::ostream_iterator<string>(cout, ", "));
            /*
             * The above is an alternate way to print to cout using the
             * STL algorithms library and iterators. This is equivalent to:
             *    for (size_t i = 0; i < ladder.size() - 1; ++i) {
             *        cout << ladder[i] << ", ";
             *    }
             */
            cout << ladder.back() << "}" << endl;
        }
    }
    return 0;
}




