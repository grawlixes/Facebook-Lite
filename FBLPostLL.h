#ifndef H_FBLPOSTLL_H
#define H_FBLPOSTLL_H

#include "FBLPost.h"

// contains node and linked list classes for posts

class FBLPostLLNode {
	public:
		FBLPostLLNode(FBLPost * newPost) {
			post = newPost;
			next_post = nullptr;
		}
		FBLPostLLNode * next_post;
		FBLPost * get_post();
	private:
		FBLPost * post;
};



class FBLPostLL {
	public:
		FBLPostLL() {
			first_post = nullptr;
		}
		void insert_new_post(FBLPost * new_post);
		void remove_first_post();
		FBLPostLL operator=(const FBLPostLL &old_LL);
		FBLPostLLNode * first_post;
	private:
};

#endif
