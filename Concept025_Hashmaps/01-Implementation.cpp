#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // Creation
    unordered_map <string, int> um;



    // Insertion
    // 1)
    pair<string, int> p = make_pair("kuldeep", 3);
    um.insert(p);          // <kuldeep, 3>

    // 2)
    pair<string, int> p2("Vibhu", 10);
    um.insert(p2);

    // 3)
    um["Vrajesh"] = 2; // insert or update



    // Search
    // 1)
    cout << um["Unknown"] << endl;        // return 0 when not found  this will make entry <"Unknown", 0> 

    // 2)
    cout << um.at("Vibhu") << endl;      // terminate called after throwing an instance of 'std::out_of_range' what():  _Map_base::at


    // Size
    cout << "Size: " << um.size() << endl;


    // Count
    cout << um.count("Kuldeep") << endl;  // absent->0
    cout << um.count("Vibhu") << endl;   // present->1


    // Erase
    um.erase("Unknown");
    cout << "Size: " << um.size() << endl;


    // Traverse
    for(auto i : um){
        cout << i.first << " " << i.second << endl;
    } cout << endl;

    // Using Iterator
    unordered_map <string, int> :: iterator it = um.begin();

    while(it != um.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    // if we used map instead of unordered map, order is preserved
    // cout << um["Vrajesh"];

    return 0;
}