#ifndef H_FBLUSER_H
#define H_FBLUSER_H

#include "FBLPostLL.h"

class FBLUser {
	public:
		FBLUser() {
			user_id = password = first = last = "";
			post_list = new FBLPostLL();
			feed = new FBLPostLL();
			friends = {};
		}
		bool create(string new_user_id, string new_password, string
			new_first, string new_last);
		string get_user_id();
		string get_password();
		string get_first();
		string get_last();
		void print_friends();
		void print_feed();
		void print_wall();
		FBLUser operator=(const FBLUser &old_user);
		~FBLUser() {
			while (post_list->first_post) {
				post_list->remove_first_post();
			}
		}
		FBLPostLL * post_list;
		FBLPostLL * feed;
		vector<FBLUser*> friends;
	private:
		string user_id;
		string password;
		string first;
		string last;
};

#endif
