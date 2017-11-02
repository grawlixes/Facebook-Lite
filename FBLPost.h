#ifndef H_FBLPOST_H
#define H_FBLPOST_H

#include "FBLCommentLL.h"

class FBLPost {
	public:
		FBLPost() {
			text = "";
			comment_list = new FBLCommentLL();
		}
		string get_full_name();
		void set_full_name(string op);
		string get_text();
		void set_text(string post_text);
		int get_likes();
		void add_like();
		FBLCommentLL * get_comment_list();
	private:
		int likes;
		FBLCommentLL * comment_list;
		string full_name;
		string text;
};

#endif
