#ifndef H_FBLUSERLL_H
#define H_FBLUSERLL_H

#include "FBLUser.h"


// contains the node and the linked list classes for users



class FBLUserLLNode {
	public:
		FBLUserLLNode() {
			user = nullptr;
			next_user = nullptr;
		}
		FBLUserLLNode(FBLUser * newUser) {
			user = newUser;
			next_user = nullptr;
		}		
		FBLUserLLNode * next_user;
		void set_info(FBLUser * new_user, FBLUserLLNode * next_user);
		FBLUser * get_user();
	private:
		FBLUser * user;
};



class FBLUserLL {
	public:
		FBLUserLL() {
			first_user = nullptr;
		}

		void insert_at_end(FBLUserLLNode * new_user);
		void check_friend_id(FBLUserLLNode * me, string new_friend_id);
		void print_user_list();
		void sort_users();

		FBLUserLLNode * first_user;

		~FBLUserLL() {
			while (this->first_user) {
				FBLUserLLNode * pointer = this->first_user;
				this->first_user = this->first_user->next_user;
				delete pointer;
			}
		}
	private:
};

#endif
