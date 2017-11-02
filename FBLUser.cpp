#include "FBLUser.h"

bool FBLUser::create(string new_user_id, string new_password,
		string new_first, string new_last) {
	this->user_id = new_user_id;
	this->password = new_password;
	this->first = new_first;
	this->last = new_last;
}

string FBLUser::get_user_id() {
	return this->user_id;
}

string FBLUser::get_password() {
	return this->password;
}

string FBLUser::get_first() {
	return this->first;
}

string FBLUser::get_last() {
	return this->last;
}

void FBLUser::print_friends() {
	if (this->friends.size() == 0) {
		cout << "You have no friends. That's rough, buddy." << endl;
	} else {
		vector<FBLUser *>::iterator it;

		for (it = this->friends.begin();it != this->friends.end(); it++) {
			cout << (*it)->get_first() << " " << (*it)->get_last() << endl;
		}
	}
	cout << endl;
}

void FBLUser::print_feed() {
	if (!this->feed->first_post) {
		cout << "Your feed is empty!" << endl;
	} else {
		FBLPostLLNode * pointer = this->feed->first_post;

		while (pointer) {
			cout << pointer->get_post()->get_full_name() << " posted:" << endl;
			cout << pointer->get_post()->get_text() << endl;

			cout << "Likes: " << pointer->get_post()->get_likes() << endl;
			
			cout << "Comments:";
			FBLCommentLLNode * comment_pointer =
				pointer->get_post()->get_comment_list()->get_first_comment();
			if (!comment_pointer) {
				cout << " None" << endl;
			} else {
				cout << endl;
			}
			while (comment_pointer) {
				cout << "\t" << comment_pointer->get_comment()->get_commenter_name()
					<< " responded:" << endl << "\t"
					<< comment_pointer->get_comment()->get_text() << endl;
				comment_pointer = comment_pointer->get_next_comment();
				cout << endl;
			}

			pointer = pointer->next_post;
			cout << endl;
		}
	}
}

void FBLUser::print_wall() {
	if (!this->post_list->first_post) {
		cout << "Your wall is empty!" << endl;
	} else {
		cout << endl;
		FBLPostLLNode * pointer = this->post_list->first_post;
		
		while (pointer) {
			cout << pointer->get_post()->get_text() << endl;
			cout << "Likes: " << pointer->get_post()->get_likes() << endl;
			
			cout << "Comments:";
			FBLCommentLLNode * comment_pointer =
				pointer->get_post()->get_comment_list()->get_first_comment();
			if (!comment_pointer) {
				cout << " None" << endl;
			} else {
				cout << endl;
			}
			while (comment_pointer) {
				cout << "\t" << comment_pointer->get_comment()->get_commenter_name()
					<< " responded:" << endl << "\t"
					<< comment_pointer->get_comment()->get_text() << endl;
				comment_pointer = comment_pointer->get_next_comment();
				cout << endl;
			}

			pointer = pointer->next_post;
			cout << endl;
		}
	}
}

FBLUser FBLUser::operator=(const FBLUser &old_user) {
	this->user_id = old_user.user_id;
	this->password = old_user.password;
	this->first = old_user.first;
	this->last = old_user.last;
}
