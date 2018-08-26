#include<iostream>


bool RegularMatch(char* str, char* pattern) {
	if (str == nullptr || pattern == nullptr)
		return false;
	bool match = true;
	//int len_p = sizeof(pattern) / sizeof(char);
	int len_p = strlen(pattern);
	std::cout << "len p is: " << len_p << std::endl;
	// char * pattern_ptr = pattern;
	int s_pos = 0;
	int p_pos = 0;
	while (pattern[p_pos] != '\0') {
		if (pattern[p_pos] == str[s_pos]) {
			s_pos++;
			p_pos++;
			continue;
		}
		else if (pattern[p_pos] == '.') {
			s_pos++;
			p_pos++;
			continue;
		}
		else if (pattern[p_pos] == '*') {
			while (str[s_pos] == pattern[p_pos - 1]) {
				s_pos++;
			}
			p_pos++;
		}
		else if (pattern[p_pos] != str[s_pos] &&p_pos +1 <=len_p && pattern[p_pos + 1] == '*') {
			p_pos += 2;
		}
		else {
			match = false;
			break;
		}
	}
	std::cout << "s_pos is: " << s_pos << std::endl;
	std::cout << "p_pos is: " << p_pos << std::endl;
	if (str[s_pos] != '\0')
		match = false;
	return match;
}

void RM_Test() {
	char *str = "aaa";
	char *p1 = "a.a";
	char *p2 = "ab*ac*a";
	char *p3 = "aa.a";
	char *p4 = "ab*a";
	char* pattern[] = { "a.a", "ab*a", "aa.a", "ab*a","ab"};
	//char* pattern[] = { "a.a", "ab*ac*a","ab"};
	for (int i = 0; i < 5; i++) {
		if (RegularMatch(str, pattern[i]))
			std::cout << "matched" << std::endl;
		else
			std::cout << "not matched" << std::endl;
	}
}

