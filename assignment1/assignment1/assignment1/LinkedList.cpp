//
//  LinkedList.cpp
//  Linked List
//
//  Created by Orbra Wortham on 9/4/16.
//  Copyright © 2016 Orbra Wortham. All rights reserved.
//

#include <algorithm>
#include <list>
#include <iostream>
#include "LinkedList.hpp"

CNode::CNode () {}

CNode::CNode (CNode * pNode, std::string sValue) : m_pNext(pNode),  m_sValue(sValue) {}

CNode * CNode::getNext () {
    return m_pNext;
}

void CNode::setNext(CNode * pNode) {
    delete m_pNext;
    m_pNext = pNode;
}

std::string CNode::getValue () {
    return m_sValue;
}

CNode::~CNode () {
    delete m_pNext;
}

CLinkedList::CLinkedList () {}

void CLinkedList::insertNode (std::string sValue) {
    m_pHead = new CNode(m_pHead, sValue);
}

bool CLinkedList::deleteNode (std::string sValue) {
    std::cout << "Deleting node... " << sValue << std::endl;
    CNode * pCurrent = m_pHead;
    if (pCurrent->getValue() == sValue) {
        delete pCurrent;
        m_pHead = pCurrent->getNext();
        return true;
    } else {
        while (pCurrent->getNext() != NULL) {
            if (pCurrent->getNext()->getValue() == sValue) {
                pCurrent->setNext(pCurrent->getNext()->getNext());
                // delete pNext;
                return true;
            }
            pCurrent = pCurrent->getNext();
        }
    std::cout << "Node does not exist... " << sValue << std::endl;
    return false;
    }
}

CNode * CLinkedList::getNextNode (std::string sValue) {
    std::cout << "Finding node... " << sValue << std::endl;
    CNode * pCurrent = m_pHead;
    while (pCurrent != NULL) {
        if (pCurrent->getValue() == sValue) {
            return pCurrent->getNext();
        }
        pCurrent = pCurrent->getNext();
    }
    std::cout << "Node does not exist... " << sValue << std::endl;
    return NULL;
}

CNode * CLinkedList::returnHead() {
    return m_pHead;
}

void CLinkedList::appendList (CLinkedList pLinkedList) {
    std::cout << "appending" << std::endl;
    CNode * pCurrent = m_pHead;
    if (pCurrent == NULL) {
        m_pHead = pLinkedList.returnHead();
    } else {
        while (pCurrent->getNext() != NULL) {
            pCurrent = pCurrent->getNext();
        }
        pCurrent->setNext(pLinkedList.returnHead());
    }
}

void CLinkedList::printList () {
    CNode * pCurrent = m_pHead;
    while (pCurrent != NULL) {
        std::cout << pCurrent->getValue() << " -> ";
        pCurrent = pCurrent->getNext();
    }
    std::cout << "NULL" << std::endl;
}

CLinkedList::~CLinkedList() {
    // TODO This destructor causes an infinite loop
    /*
    while (m_pHead != NULL) {
        CNode * pTemp = m_pHead->getNext();
        delete m_pHead;
        m_pHead = pTemp;
    }
     */
}

CLinkedList Combine (std::list<CLinkedList::CLinkedList> listOfLists) {
    CLinkedList CombinedList = CLinkedList();
    for (std::list<CLinkedList::CLinkedList>::iterator it=listOfLists.begin(); it != listOfLists.end(); ++it){
        //CombinedList.printList();
        CombinedList.appendList(*it);
        //CombinedList.printList();
    }
    return CombinedList;
};
