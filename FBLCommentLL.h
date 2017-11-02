#ifndef H_FBLCOMMENTLL_H
#define H_FBLCOMMENTLL_H

#include "FBLComment.h"

class FBLCommentLLNode {
	public:
		FBLCommentLLNode(FBLComment * comment) {
			this->comment = comment;
			this->next_comment = nullptr;
			this->previous_comment = nullptr;
		}
		FBLComment * get_comment();
		FBLCommentLLNode * get_next_comment();
		void set_next_comment(FBLCommentLLNode * new_comment);
		FBLCommentLLNode * get_previous_comment();
		void set_previous_comment(FBLCommentLLNode * new_comment);
	private:
		FBLComment * comment;
		FBLCommentLLNode * next_comment;
		FBLCommentLLNode * previous_comment;
};

class FBLCommentLL {
	public:
		FBLCommentLL() {
			this->first_comment = nullptr;
		}
		FBLCommentLLNode * get_first_comment();
		FBLCommentLLNode * get_last_comment();
		void set_first_comment(FBLCommentLLNode * new_comment);
		void set_last_comment(FBLCommentLLNode * new_comment);
		void insert_new_comment(FBLComment * new_comment);
		void read_az();
		void read_za();
	private:
		FBLCommentLLNode * first_comment;
		FBLCommentLLNode * last_comment;
};

#endif
