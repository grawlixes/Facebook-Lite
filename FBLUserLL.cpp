#include "FBLUserLL.h"

FBLUser * FBLUserLLNode::get_user() {
	return this->user;
}

void FBLUserLL::insert_at_end(FBLUserLLNode * new_user_node) {
	FBLUserLLNode * pointer = this->first_user;	
	if (pointer) {
		while (pointer->next_user) {
			pointer = pointer->next_user;
		}
		pointer->next_user = new_user_node;
	} else {
		this->first_user = new_user_node;
	}
}

void FBLUserLL::check_friend_id(FBLUserLLNode * me, string new_friend_id) {
	FBLUserLLNode * pointer = this->first_user;
	int check = 0;
	while (pointer) {
		if (pointer->get_user()->get_user_id() == new_friend_id) {
			vector<FBLUser *>::iterator it;
			int already_in_list = 0;
			for(it = me->get_user()->friends.begin();it != 
			    me->get_user()->friends.end();it++) {
				if (new_friend_id == (*it)->get_user_id()) {
					already_in_list = 1;	
				}
			}

			if (already_in_list) {
				cout << "That user is already your friend." 
					<< endl;
				check = 1;
				pointer = nullptr;
			} else {
				me->get_user()->friends.push_back(pointer->get_user());
				pointer->get_user()->friends.push_back(me->get_user());
				check = 1;
				cout << "Successfully added " << new_friend_id
					<< " to your friends list!" << endl;
				pointer = nullptr;
			}
		} else {
			pointer = pointer->next_user;
		}
	}
	if (check == 0) {
		cout << "User not found." << endl;
	}
	cout << endl;
}

void FBLUserLL::print_user_list() {
	FBLUserLLNode * pointer = this->first_user;
	if (pointer) {
		while (pointer) {
			cout << pointer->get_user()->get_last() << ", "
				<< pointer->get_user()->get_first()
				<< " <" << pointer->get_user()->get_user_id()
				<< ">" << endl;
			pointer = pointer->next_user;	
		}
	} else {
		cout << "No users exist." << endl;
	}
}

void FBLUserLL::sort_users() {
	FBLUserLLNode * pointer;
	int repeat;
	int is_first_user;
	if (this->first_user) {
		repeat = 1;
	} else {
		cout << "No users exist." << endl;
		repeat = 0;
	}
	while (repeat) {
		pointer = this->first_user;
		repeat = 0;
		is_first_user = 1;
		FBLUserLLNode * previous;
		while (pointer) {
			if (pointer->next_user) {
				if (pointer->get_user()->get_last() > 
				    pointer->next_user->get_user()->get_last()) {
					FBLUserLLNode * temp = pointer->next_user;
					if (pointer->next_user->next_user) {
						pointer->next_user = pointer->next_user->next_user;
					} else {
						pointer->next_user = nullptr;
					}
					temp->next_user = pointer;
					pointer = temp;
					if (is_first_user) {
						this->first_user = pointer;
					} else {
						previous->next_user = pointer;
					}
					repeat = 1;
				}
			}	
			is_first_user = 0;
			previous = pointer;
			pointer = pointer->next_user;
		}
	}

}

void FBLUserLLNode::set_info(FBLUser * new_user, FBLUserLLNode * next_user) {
	this->user = new_user;
	this->next_user = next_user;
} 
