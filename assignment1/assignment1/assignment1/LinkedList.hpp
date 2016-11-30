//
//  LinkedList.hpp
//  Linked List
//
//  Created by Orbra Wortham on 9/4/16.
//  Copyright © 2016 Orbra Wortham. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <list>
#include <stdio.h>
#include <string>

class CNode {
    
    CNode * m_pNext = NULL;
    std::string m_sValue = NULL;
    
public:
    CNode();
    CNode(CNode * pNode, std::string sValue);
    CNode * getNext();
    void setNext(CNode * pNode);
    std::string getValue();
    ~CNode();
};

class CLinkedList {
    
    CNode * m_pHead = NULL;
    
public:
    CLinkedList();
    void insertNode(std::string sValue);
    bool deleteNode(std::string sValue);
    CNode * getNextNode(std::string);
    CNode * returnHead();
    void appendList(CLinkedList pLinkedList);
    void printList();
    ~CLinkedList();
};

CLinkedList Combine(std::list<CLinkedList::CLinkedList> listOfLists);
 
#endif /* LinkedList_hpp */
