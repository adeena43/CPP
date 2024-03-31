#include <iostream>
using namespace std;

class Post;
class RegularUser;
class BusinessUser;

void passwordEncryption(string& password) {
    string key = "nothing";
    for (int i = 0; i < password.length(); i++) {
        password[i] = password[i] ^ key[i % key.length()];
    }
}

void passwordDecryption(string& password) {
    passwordEncryption(password); // Decryption is the same as encryption for XOR
}

class Post {
public:
    int postId;
    string content;
    int likes;
    string comments[100];
    int no_of_comments;
    int views;

    Post(int postId, string content) : content(content), postId(postId), likes(0), no_of_comments(0), views(0) {}

    void addingComments(string comment) {
        comments[no_of_comments] = comment;
        no_of_comments++;
    }

    void like() {
        likes++;
    }
    void view() {
        views++;
    }
    void setLikes(int x)
    {
        likes*=x;
    }
    
     void setViews(int x)
    {
        views*=x;
    }

    void displaypostdetails() {
        cout << "The post id is = " << postId << endl
             << "content = " << content << endl
             << "likes = " << likes << endl
             << "no of Comments = " << no_of_comments << endl
             << "views = " << views<<endl;

        cout << endl;
    }
};

class User {
public:
    string username;
    string email;
    string password;

    User(string username, string email, string password) : username(username), email(email), password(password) {}

    virtual bool verifyUser(string inputPassword) = 0;

    void printVerificationMessage(bool verified) {
        if (verified) {
            cout << "User verified" << endl;
        }
    }
};

class RegularUser : public User {
public:
    int feedSize;
    static const int MAX_FEED_SIZE = 10;
    Post* feed[MAX_FEED_SIZE];

    RegularUser(string username, string email, string password) : User(username, email, password), feedSize(0) {}

    void addToFeed(Post &fe) {
        if (feedSize <= 5) {
            feed[feedSize] = &fe;
            feedSize++;
        } else {
            cout << "Regular User can post a maximum of 5 posts" << endl;
            return;
        }
    }

    void viewFeed() {
        for (int i = 0; i < feedSize; i++) {
            feed[i]->displaypostdetails();
        }
    }

    bool verifyUser(string inputPassword) override {
        string decryptedPassword = inputPassword;
        passwordDecryption(decryptedPassword);
        bool verified = decryptedPassword == password;
        printVerificationMessage(verified);
        return verified;
    }
};

class BusinessUser : public User {
public:
    int promotionLimit = 10;
    static int countpromote;

    BusinessUser(string username, string email, string password) : User(username, email, password) {}

    void promotePost(Post &post) {
        if (checkPromotionLimit(post)) {
            cout << "Your post is promoted" << endl;
            post.setLikes(2);
            post.setViews(3);
        }
    }

    bool checkPromotionLimit(Post &post) {
        if (countpromote > promotionLimit) {
            cout << "Can't promote more, the maximum post promotion limit reached" << endl;
            return 0;
        }
        countpromote++;
        return 1;
    }

    bool verifyUser(string inputPassword) override {
        string decryptedPassword = inputPassword;
        passwordDecryption(decryptedPassword);
        bool verified = decryptedPassword == password;
        printVerificationMessage(verified);
        return verified;
    }
};
int BusinessUser::countpromote = 0;

int main() {
	cout<<"Adina Faraz"<<"23k-0008"<<endl;
    RegularUser regularUser("user1", "user1@example.com", "password1");
    BusinessUser businessUser("business1", "business1@example.com", "password2");

    cout << "User1 verified: " << regularUser.verifyUser("password1") << endl;
    cout << "User2 verified: " << businessUser.verifyUser("password2") << endl;

    Post post1(001, "Hello");
    Post post2(112, "Feeling happy");
    Post post3(113, "Completed my school");

    regularUser.addToFeed(post1);
    regularUser.addToFeed(post2);
    regularUser.addToFeed(post3);

    regularUser.viewFeed();
    post3.like();
    businessUser.promotePost(post3);
    post2.displaypostdetails();
    post3.displaypostdetails();

    return 0;
}
