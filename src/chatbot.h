#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    //Task 0
    //wxBitmap *_image; // avatar image
    std::shared_ptr<wxBitmap> _image;

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // Task 2:
    //copy constructor 
    ChatBot(const ChatBot &);

    //copy assignment constructor
    ChatBot &operator=(const ChatBot &);

    // move constructor
    ChatBot(ChatBot &&);

    //move assignment operator
    ChatBot &operator=(ChatBot &&);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    //Task 0
    //wxBitmap *GetImageHandle() { return _image; }
    std::shared_ptr<wxBitmap> GetImageHandle() { return _image; }


    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
