#Boyer–Moore string search algorithm

In computer science, the Boyer–Moore string search algorithm is an
efficient string searching algorithm that is the standard benchmark for
practical string search literature. It was developed by Robert S.
Boyer and J Strother Moore in 1977. The algorithm preprocesses the
string being searched for (the pattern), but not the string being
searched in (the text).

###Complexity
* Preprocessing phase in O(m+sigma) time and space complexity;
* Searching phase in O(mn) time complexity;
* 3n text character comparisons in the worst case when searching for a non periodic pattern;
* O(n / m) best performance.
