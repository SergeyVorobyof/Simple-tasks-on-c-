#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Binary_Tree {
    private:
        int root;
    public:
	deque<vector<int> > vertex;
	void set_root(int potential_root) {
	    root = potential_root;
	    vector<int> arr(3);
	    arr[0] = root;
	    arr[1] = -1;
	    arr[2] = -1;
            vertex.push_back(arr);
	}

	void show() {
    	    for(int i = 0; i < vertex.size(); ++i) {
		cout << "(" << vertex[i][0] << ",";
		cout << vertex[i][1] << ",";
		cout << vertex[i][2] << ")" << endl;
            }	    
	}

	void add_element(int potential_elem) {
	    for (int i = 0;;) {
		    if (potential_elem <= vertex[i][0]){
			cout << "potential_elem <= vertex[" << i << "][0]" << endl;
			if (potential_elem <= vertex[i][1] && i != 0) {
			    i--;
			}
			else if (potential_elem > vertex[i][1]) {
			    if (i != 0) {
			        if (vertex[i][1] == -1 && (potential_elem > vertex[i-1][0] || (i-1) == 0)) {
				    vertex[i][1] = potential_elem;
				    vector<int> arr(3);
				    arr[0] = potential_elem;
				    arr[1] = -1;
				    arr[2] = -1;
				    vertex.push_front(arr);
				    break;
			        }
			        i--;
			    }
			    else if (i == 0) {
				if (vertex[i][1] == -1) {
				    vertex[i][1] = potential_elem;
				    vector<int> arr(3);
				    arr[0] = potential_elem;
				    arr[1] = -1;
				    arr[2] = -1;
				    vertex.push_front(arr);
				    break;					
				}
			    }
			}
		    }

		    else if (potential_elem > vertex[i][0]) {
			cout << "potential_elem > vertex[" << i << "][0]" << endl;
			if (potential_elem <= vertex[i][2] && i < vertex.size()) {
			    i++;
			}
			else if (potential_elem > vertex[i][2]) {
			    if (i != vertex.size() - 1) {
			        if (vertex[i][2] == -1 && (potential_elem < vertex[i+1][0] || (i+1) == vertex.size())) {
				    vertex[i][2] = potential_elem;
				    vector<int> arr(3);
				    arr[0] = potential_elem;
				    arr[1] = -1;
				    arr[2] = -1;
				    vertex.push_back(arr);
				    break;
			        }
			        i++;
			    }
			    else if (i == vertex.size() - 1) {
			        if (vertex[i][2] == -1) {
				    vertex[i][2] = potential_elem;
				    vector<int> arr(3);
				    arr[0] = potential_elem;
				    arr[1] = -1;
				    arr[2] = -1;
				    vertex.push_back(arr);
				    break;
			        }
			    }			
			}
		    }

	    }
	    sort(vertex.begin(), vertex.end());
	}
};

int main(){
    Binary_Tree bt;
    int elem, potential;
    cin >> elem;
    bt.set_root(elem);

    // We use 6 elements, however you may use any number.
    int count = 0;
    while(count < 6) {
	cout << "input elem is: ";
        cin >> potential;
        bt.add_element(potential);
        count++;
	cout << "input is over" << endl;
    }
    
    bt.show();
    return 0;
}
