/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:11:00 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/29 11:30:06 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

void testWithMutantStack()
{
    std::cout << "=== Testing with MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "Stack created from MutantStack, size: " << s.size() << std::endl;
}

void testWithList()
{
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    
    std::list<int> mstack;  // Using same variable name for clarity
    
    mstack.push_back(5);     // push() becomes push_back()
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;  // top() becomes back()
    
    mstack.pop_back();  // pop() becomes pop_back()
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(mstack);
    std::cout << "List created from list, size: " << s.size() << std::endl;
}

void testWithVector()
{
    std::cout << "\n=== Testing with std::vector ===" << std::endl;
    
    std::vector<int> mstack;
    
    mstack.push_back(5);
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;
    
    mstack.pop_back();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::vector<int>::iterator it = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::vector<int> s(mstack);
    std::cout << "Vector created from vector, size: " << s.size() << std::endl;
}

void subjectTest()
{
    std::cout << "\n=== Subject's Exact Test ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
}

int main()
{
    // Run the exact test from the subject
    subjectTest();
    
    // Compare with other containers
    testWithMutantStack();
    testWithList();
    testWithVector();
    
    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // Test that MutantStack works with different underlying containers
    std::cout << "\nMutantStack with std::list as underlying container:" << std::endl;
    MutantStack<int, std::list<int> > mstack_list;
    mstack_list.push(10);
    mstack_list.push(20);
    mstack_list.push(30);
    
    for (MutantStack<int, std::list<int> >::iterator it = mstack_list.begin();
         it != mstack_list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    std::cout << "\nMutantStack with std::vector as underlying container:" << std::endl;
    MutantStack<int, std::vector<int> > mstack_vector;
    mstack_vector.push(100);
    mstack_vector.push(200);
    mstack_vector.push(300);
    
    for (MutantStack<int, std::vector<int> >::iterator it = mstack_vector.begin();
         it != mstack_vector.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    return 0;
}