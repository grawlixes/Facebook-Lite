#include "FBLPostLL.h"

FBLPost * FBLPostLLNode::get_post() {
	return this->post;
}

void FBLPostLL::insert_new_post(FBLPost * new_post) {
	FBLPostLLNode * pointer = this->first_post;
	if (pointer) {
		while (pointer->next_post) {
			pointer = pointer->next_post;
		}	
		pointer->next_post = new FBLPostLLNode(new_post);
	} else {
		this->first_post = new FBLPostLLNode(new_post);
	} 
/*	if (add_to_friends) {
		vector<FBLUser *>::iterator it;
		for (it = me->friends.begin();it !=
		     me->friends.end();it++) {
			it->feed->insert_new_post(nullptr, new_post, false);
		}
	}*/
}

void FBLPostLL::remove_first_post() {
	FBLPostLLNode * pointer = this->first_post;
	this->first_post = this->first_post->next_post;
	delete pointer;
}

FBLPostLL FBLPostLL::operator=(const FBLPostLL &old_LL) {
	this->first_post = old_LL.first_post;
}
