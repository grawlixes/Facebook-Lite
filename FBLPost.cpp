#include "FBLPost.h"

string FBLPost::get_full_name() {
	return this->full_name;
}

void FBLPost::set_full_name(string op) {
	this->full_name = op;
}

string FBLPost::get_text() {
	return this->text;
}

void FBLPost::set_text(string post_text) {
	this->text = post_text;
}

int FBLPost::get_likes() {
	return this->likes;
}

void FBLPost::add_like() {
	this->likes += 1;
}

FBLCommentLL * FBLPost::get_comment_list() {
	return this->comment_list;
}
