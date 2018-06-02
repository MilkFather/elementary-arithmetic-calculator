#include "calc.hpp"

queue<string> lexical(string s) {
    std::queue<string> v;
    int currentat = 0;
    // look-forward
    while (currentat < s.length()) {
        int looklength = 1;
        if (in(s[currentat + looklength - 1], operators, operators_count)) {
            // operators are always one char long.
            v.push(s.substr(currentat, looklength));
            currentat += looklength;
        } else if (in(s[currentat + looklength - 1], numerics, numerics_count)){
            // numbers. the validity of numbers is not tested at this time
            while (currentat + looklength - 1 < s.length()) // read until not numeric, incuding EOL, space and operators
                if (in(s[currentat + looklength], numerics, numerics_count))
                    looklength += 1;
                else break;
            v.push(s.substr(currentat, looklength));
            currentat += looklength;
        } else if (isspace(s[currentat + looklength - 1])) {
            currentat += looklength; // skip spaces
        } else {
            stringstream whatmsg;
            whatmsg << "The char '" << s[currentat + looklength - 1] <<"' is not valid (permitted) in a math expression.";
            throw invalid_argument(whatmsg.str());
        }
    }
    return v;
}
