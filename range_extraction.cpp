#include <string>
#include <vector>
#include <string>
#include <deque>

std::string range_extraction(std::vector<int> args) {
    // Handling some cases
    if (args.empty()) {
        return "";
    } else if (args.size() == 1) {
        return std::to_string(args[0]);
    }
    
    std::string result = "";
    std::deque<int> tempQueue; // Double ended queue storing temporarily the elements
    int seq = 0; // counting how big is the temporary sequence
    bool f = true; // it is true if the element is the first value of the sequence
    for (size_t i = 0; i < args.size(); i++) {
        if (f) {
            tempQueue.push_back(args[i]);
            f = false;
        }

        // If it is the last iteration
        if (i == args.size() - 1) {
            // Storing the elements in the correct notation
            if (args[i] - 1 == args[i - 1]) {
                tempQueue.push_back(args[i]);
                if (seq >= 2) {
                    result += std::to_string(tempQueue.front()) + "-" + std::to_string(tempQueue.back()) + ",";
                } else if (seq == 1) {
                    result += std::to_string(tempQueue.front()) + "," + std::to_string(tempQueue.back()) + ",";
                }
            } else {
                result += std::to_string(tempQueue.front()) + ",";
            }

            // removing the comma(,) character from the back of the string
            result = result.substr(0, result.size() - 1);
            return result;
        }

        if (args[i] + 1 == args[i+1]) {
            // Incrementing the temporary sequence variable
            seq++;
        } else {
            // Pushing the last element of the temporary sequence in the double ended queue
            if (seq >= 1 && args[i] - 1 == args[i - 1]) {
                tempQueue.push_back(args[i]);
            }

            // Storing the elements in the correct notation
            if (seq >= 2) {
                result += std::to_string(tempQueue.front()) + "-" + std::to_string(tempQueue.back()) + ",";
            } else if (seq == 1) {
                result += std::to_string(tempQueue.front()) + "," + std::to_string(tempQueue.back()) + ",";
            } else {
                result += std::to_string(tempQueue.front()) + ",";
            }

            // Clearing the queue
            tempQueue.clear();
            seq = 0;
            f = true;
        }
    }
}
