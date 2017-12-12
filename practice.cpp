/*
 * practice.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: root
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	vector<int> res;
	for (size_t i = 0; i < nums.size(); i++) {
		if (m.find(target - nums[i]) != m.end()) {
			res.push_back(m[target - nums[i]]);
			res.push_back(i);
			break;
		} else
			m[nums[i]] = i;
	}
	return res;
}

//Reverse a link list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* reverseList(ListNode* head) {
	ListNode *current = head, *previous = NULL, *tmp;
	while (current) {
		tmp = current->next;
		current->next = previous;
		previous = current;
		current = tmp;
	}
	return previous;
}

//Isomorphic strings
bool isIsomorphic(string& s, string& t) {
	int m1[256] = { 0 }, m2[256] = { 0 }, n = s.size();
	for (int i = 0; i < n; ++i) {
		if (m1[(unsigned char)s[i]] != m2[(unsigned char)t[i]])
			return false;
		m1[(unsigned char)s[i]] = i + 1;
		m2[(unsigned char)t[i]] = i + 1;
	}
	return true;
}

int main() {
	string s = "egg", t = "add";
	bool result = isIsomorphic(s,t);
	cout << result;
}

