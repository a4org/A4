/*
 *LeetCode T142 :LinkedListCycleii.cpp
 *medium
 *fs
 *2021.7.26
 */

/**                                                                                                     head       entrance
 *   Consider of running efficency and simplicity ,we can seting two pointer with diffrent speeds,        o ___(a)____o_________(b)_
 * so in a linked list cycle they will must be meet each other.                                                       |              \
 *   In the cycle ,when the faster one(Fp for short) meet the slow one(Sp) ,the distance Fp has pass                  |               |
 * is:                                                                                                                \__(c)__o______/
 *         @ a+ b+ n(b+ c) = a+ nc+ b(n+ 1)             n:QuanShu                                                            meet at here
 * if the speed of Fp is twice as Sp:
 *         @ a+ nc+ b(n+ 1) = 2(a+ b)                                                                             Linked List Cycle
 * also:   @ a = c+ (n− 1)(b+ c)
 * Fp and Sp will meet at the first round (n= 1),as a result:
 *         @ a = c
**/           


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
                                                                                                       
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* Fast_point = head;    //The faster one
        ListNode* Slow_point = head;    //The slower one
        ListNode* Ano_point = head;     //The pointer used to find the entrance (another_point)
        int num = 0;
        
        for(int i = 0; head != NULL && head->next !=NULL ; ++i){
            if(Fast_point->next!= 0 && Fast_point->next->next != 0){
                Fast_point = Fast_point->next ->next;
                Slow_point = Slow_point->next;
            }
            else
                break; 
          
            if(Fast_point == Slow_point)
                num=1;  
            if(Ano_point == Slow_point && num==1 )
                return Slow_point;
            if(num == 1)
                Ano_point = Ano_point ->next;    
            //head =head -> next;     
        }
    return nullptr;    
    }
};
