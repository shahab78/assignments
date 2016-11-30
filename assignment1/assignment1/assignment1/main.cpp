//
//  main.cpp
//  assignment1
//
//  Created by Orbra Wortham on 9/4/16.
//  Copyright © 2016 Orbra Wortham. All rights reserved.
//

#include <iostream>
#include <list>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << "Let's create a linked list and add some nodes!!" << std::endl;
    
    // Create first linked list
    std::cout << "Creating first LL..." << std::endl;
    CLinkedList alpha = CLinkedList();
    
    // Add Nodes
    alpha.insertNode("Bb");
    alpha.insertNode("Cc");
    alpha.insertNode("Dd");
    
    alpha.printList();
    
    // Create second linked list
    std::cout << "Creating second LL..." << std::endl;
    CLinkedList beta = CLinkedList();
    
    // Add Nodes
    beta.insertNode("Ff");
    beta.insertNode("Hh");
    beta.insertNode("Ii");
    
    beta.printList();
    
    // Create third linked list
    std::cout << "Creating third LL..." << std::endl;
    CLinkedList gamma = CLinkedList();
    
    
    // Add Nodes
    gamma.insertNode("Jj");
    gamma.insertNode("Kk");
    gamma.insertNode("Ll");
    gamma.insertNode("Mm");
    gamma.insertNode("Oo");
    
    gamma.printList();
    
    
    std::cout << "Now let's delete some nodes!!!!" << std::endl;
    
    // Delete items from the initial nodes
    alpha.deleteNode("Bb");
    beta.deleteNode("Ff");
    
    std::cout << "Print first list again..." << std::endl;
    alpha.printList();
    
    std::cout << "Print second list again..." << std::endl;
    beta.printList();
    
    
    std::list<CLinkedList> list_of_lists;
    
    list_of_lists.push_back(alpha);
    list_of_lists.push_back(beta);
    list_of_lists.push_back(gamma);
    
    std::cout << "Let's append a list to another..." << std::endl;
    
    // TODO appending before sending to list causes an infinite loop
    //alpha.appendList(beta);
    //alpha.printList();
    
    std::cout << "Now we combine a list of lists..." << std::endl;
    CLinkedList delta = Combine(list_of_lists);
    
    delta.printList();
    
    return 0;
}
