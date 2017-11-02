#ifndef H_FBLCOMMENT_H
#define H_FBLCOMMENT_H

#include <string>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class FBLComment {
	public:
		FBLComment(string commenter_name, string text) {
			this->commenter_name = commenter_name;
			this->text = text;
		}
		string get_commenter_name();
		string get_text();
	private:
		string commenter_name;
		string text;
};

#endif
