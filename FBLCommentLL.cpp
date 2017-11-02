#include "FBLCommentLL.h"

FBLComment * FBLCommentLLNode::get_comment() {
	return this->comment;
}

FBLCommentLLNode * FBLCommentLLNode::get_next_comment() {
	return this->next_comment;
}

void FBLCommentLLNode::set_next_comment(FBLCommentLLNode * new_comment) {
	this->next_comment = new_comment;
}

FBLCommentLLNode * FBLCommentLLNode::get_previous_comment() {
	return this->previous_comment;
}

void FBLCommentLLNode::set_previous_comment(FBLCommentLLNode * new_comment) {
	this->previous_comment = new_comment;
}

// ----

FBLCommentLLNode * FBLCommentLL::get_first_comment() {
	return this->first_comment;
}

FBLCommentLLNode * FBLCommentLL::get_last_comment() {
	return this->last_comment;
}

void FBLCommentLL::set_first_comment(FBLCommentLLNode * new_comment) {
	this->first_comment = new_comment;
}

void FBLCommentLL::set_last_comment(FBLCommentLLNode * new_comment) {
	this->last_comment = new_comment;
}

void FBLCommentLL::insert_new_comment(FBLComment * new_comment) {
	FBLCommentLLNode * pointer = this->get_first_comment();
	if (pointer) {
		while (pointer->get_next_comment()) {
			pointer = pointer->get_next_comment();
		}
		pointer->set_next_comment(new FBLCommentLLNode(new_comment));
		FBLCommentLLNode * pointer2 = pointer->get_next_comment();
		pointer2->set_previous_comment(pointer);
		this->set_last_comment(pointer2);
		pointer = nullptr;
	} else {
		this->set_first_comment(new FBLCommentLLNode(new_comment));
		this->set_last_comment(this->get_first_comment());
	}
}

void FBLCommentLL::read_az() {
	cout << endl;
	FBLCommentLLNode * pointer = this->get_first_comment();
	if (pointer) {
		while (pointer) {
			cout << pointer->get_comment()->get_commenter_name()
				<< " commented:" << endl;
			cout << pointer->get_comment()->get_text() << endl;
			pointer = pointer->get_next_comment();
		}
	} else {
		cout << "This post has no comments." << endl;
	}
	cout << endl;
}

void FBLCommentLL::read_za() {
	cout << endl;
	FBLCommentLLNode * pointer = this->get_last_comment();
	if (pointer) {
		while (pointer) {
			cout << pointer->get_comment()->get_commenter_name()
				<< " commented:" << endl;
			cout << pointer->get_comment()->get_text() << endl;
			pointer = pointer->get_previous_comment();
		}
	} else {
		cout << "This post has no comments." << endl;
	}
	cout << endl;
}
