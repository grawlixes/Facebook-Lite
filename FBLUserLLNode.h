#include "FBLUser.h"

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
