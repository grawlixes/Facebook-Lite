#include "FBLUser.h"
#include "FBLUserLL.h"
#include "FBLPost.h"
#include "FBLPostLL.h"

void login(FBLUserLL * user_list, FBLUserLLNode * pointer);
void read(string me, FBLPost * post);
void instruct();
void instruct_2();
void instruct_3();
//void test_print(FBLUserLL * user_list);


int main(int argc, char ** argv) {
	cout << "Welcome to Facebook Lite!" << endl;
	cout << endl;
	
	FBLUserLL * user_list = new FBLUserLL();

	instruct();
	cout << endl << "> ";
	
	string choice;
	getline(cin, choice);
	while (choice != "QUIT") {
		if (choice.substr(0, 7) == "CREATE ") {
			string input = choice.substr(7);
			string new_user_id = input.substr(0, 
				input.find_first_of(" "));
			
			FBLUserLLNode * pointer = user_list->first_user;
			int reset;
			while (pointer) {
				reset = 0;
				while (new_user_id == 
					pointer->get_user()->get_user_id()) {
					cout << "Username already taken."
						<< endl;
					cout << "Try again: ";
					getline(cin, new_user_id);
					cout << endl;
					reset = 1;
				}
				// if the username was caught, start over from
				// the beginning
				if (reset) {
					pointer = user_list->first_user;
				} else {
					pointer = pointer->next_user;
				}
			}
			delete pointer;

			input = input.substr(input.find_first_of(" ") + 1);
			string new_password = input.substr(0, 
				input.find_first_of(" "));
			input = input.substr(input.find_first_of(" ") + 1);
			string new_first = input.substr(0, 
				input.find_first_of(" "));
			string new_last = input.substr(input.find_first_of(" ") + 1);
			
			FBLUser * new_user = new FBLUser();
			new_user->create(new_user_id, new_password, new_first,
				new_last);

			FBLUserLLNode * new_user_node = new FBLUserLLNode(new_user);

			user_list->insert_at_end(new_user_node);
			
			instruct();
		} else if (choice.substr(0, 6) == "LOGIN ") {
			if (!user_list->first_user) {
				cout << "No users exist!" << endl;
				cout << endl;
			} else {
				choice = choice.substr(6);
				string user_id_input = choice.substr(0, 
					choice.find_first_of(" "));
				string password_input = 
					choice.substr(choice.find_first_of(" ")+1);
				
				FBLUserLLNode * pointer = user_list->first_user;
				int x = 0;
				while (x == 0) {
					if (user_id_input == 
					    pointer->get_user()->get_user_id() and 
					    password_input == 
					    pointer->get_user()->get_password()) {
						cout << "Successfully logged in." << endl;
						x = 1;
					} else {
						if (pointer->next_user) {
							pointer = pointer->next_user;
						} else {
							cout << 
							"User and password did not match.";
							cout << endl;
							x = 2;
						}
					}
				}
				cout << endl;
				if (x == 1) {
					login(user_list, pointer);
				}
			}
			instruct();
		} else if (choice == "USERS") {
			user_list->print_user_list();
			cout << endl;
			instruct();
		} else if (choice == "SORTUSERS") {
			user_list->sort_users();
			cout << endl;
			instruct();
		} else {
			cout << "Unrecognized input, please try again."
				<< endl;
			cout << endl;

			instruct();
		}
		cout << endl;
		cout << "> ";
		getline(cin, choice);
	}
//	test_print(user_list);
	cout << "Thanks for using FB Lite!" << endl;

	delete user_list;

	return 0;
}

void login(FBLUserLL * user_list, FBLUserLLNode * pointer) {
	instruct_2();
	cout << endl;
	cout << "> ";
	string choice;
	getline(cin, choice);
	
	while (choice != "LOGOUT") {
		if (choice.substr(0, 5) == "POST ") {
			string post_text = choice.substr(5);
	
			FBLPost * new_post = new FBLPost();
			new_post->set_text(post_text);

			string op = pointer->get_user()->get_first() + " " + 
				pointer->get_user()->get_last();
			new_post->set_full_name(op);
			//insert to users wall
			pointer->get_user()->post_list->insert_new_post(new_post);
			//insert to friends' feeds
			vector<FBLUser *>::iterator it;
			for(it = pointer->get_user()->friends.begin();it !=
			    pointer->get_user()->friends.end();it++) {
				(*it)->feed->insert_new_post(new_post);
			}
		} else if (choice == "READ") {
			if (!pointer->get_user()->feed->first_post) {
				cout << "Nothing to READ" << endl;
			} else {
				//reads from feed and deletes
				cout << pointer->get_user()->feed->first_post->get_post()->get_full_name()
					<< " posted:" << endl;
				cout << pointer->get_user()->feed->first_post->get_post()->get_text()
					<< endl;
				cout << endl;

				string me = pointer->get_user()->get_first() + " " +
					    pointer->get_user()->get_last();

				read(me, pointer->get_user()->feed->first_post->get_post());

				pointer->get_user()->feed->remove_first_post();

			}
		} else if (choice.substr(0, 7) == "FRIEND ") {
			string new_friend_id = choice.substr(7);
			
			if (new_friend_id == pointer->get_user()->get_user_id()) {
				cout << "That's you! Go outside and make some friends!" << endl;
				cout << endl;
			} else {
				user_list->check_friend_id(pointer, new_friend_id);
			}
		} else if (choice == "MYFRIENDS") {
			pointer->get_user()->print_friends();
		} else if (choice == "MYFEED") {
			pointer->get_user()->print_feed();
		} else if (choice == "MYWALL") {
			pointer->get_user()->print_wall();
		} else {
			cout << "Unrecognized input. Please try again." << endl;
		}
		instruct_2();
		cout << endl;
		cout << "> ";
		getline(cin, choice);
	}
}

void read(string me, FBLPost * post) {
	instruct_3();
	cout << endl;
	cout << "> ";
	string choice;
	getline(cin, choice);
	while (choice != "DONE") {
		if (choice == "LIKE") {
			post->add_like();
			cout << "You liked this post." << endl;
		} else if (choice.substr(0, 8) == "COMMENT ") {
			string comment_input = choice.substr(8);
		
			FBLComment * new_comment = new
				FBLComment(me, comment_input);
			post->get_comment_list()->insert_new_comment(new_comment);
		} else if (choice == "READ_AZ") {
			post->get_comment_list()->read_az();
		} else if (choice == "READ_ZA") {
			post->get_comment_list()->read_za();
		} else {
			cout << "Unrecognized input. Try again." << endl;
		}
		instruct_3();
		cout << endl;
		cout << "> ";
		getline(cin, choice);
	}
}

//for cleanliness, I made this its own function
void instruct() {
	cout << "Do any of the following:" << endl;
	cout << "CREATE <userid> <password> <first> <last>" << endl;
	cout << "LOGIN <userid> <password>" << endl;
	cout << "USERS" << endl;
	cout << "SORTUSERS" << endl;
	cout << "QUIT" << endl;
}

//same thing but for the 2nd level menu
void instruct_2() {
	cout << "You are logged in. Choose:" << endl;
	cout << "POST <text>" << endl;
	cout << "READ" << endl;
	cout << "FRIEND <userid>" << endl;
	cout << "MYFRIENDS" << endl;
	cout << "MYFEED" << endl;
	cout << "MYWALL" << endl;
	cout << "LOGOUT" << endl;
}

void instruct_3() {
	cout << "You are viewing a comment. Choose:" << endl;
	cout << "LIKE" << endl;
	cout << "COMMENT <text" << endl;
	cout << "READ_AZ" << endl;
	cout << "READ_ZA" << endl;
	cout << "DONE" << endl;
}

/*void test_print(FBLUserLL * user_list) {
	FBLUserLLNode * pointer = user_list->first_user;
	while (pointer) {
		cout << pointer->get_user()->get_user_id() << endl;
		if (pointer->next_user) {
			pointer = pointer->next_user;
		} else {
			pointer = nullptr;
		}
	}
	delete pointer;
}*/
