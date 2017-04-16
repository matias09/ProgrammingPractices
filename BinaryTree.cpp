#include <iostream>
#include <stdexcept>

// Own Classes
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  std::cout << " \n Building BinaryTree . . . \n";
  mCountGreatestNumbers = 0;
  mCountLowestNumbers = 0;
  mCount = 0;
  mHeadNode = nullptr;
}

BinaryTree::~BinaryTree()
{
  std::cout << " \n Releasing BinaryTree . . . \n";
}

void BinaryTree::ShowElements()
{
  if (mHeadNode != nullptr)
  {
    std::cout << "Nodes Values : ";
    ShowNode(mHeadNode);
  }
  else
  {
    std::cout << "Empty Container";
  }
}

// This will be change to return a Json string
void BinaryTree::ShowNode(Node* node)
{
  std::cout << node->n << " ";
  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      ShowNode(node->mLower);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      ShowNode(node->mGreater);
    }
    node->mRightDirectionTaken = true;
  }
    node->mLeftDirectionTaken = false;
    node->mRightDirectionTaken = false;
}

void BinaryTree::Insert(const int n)
{
  try
  {
    if (mHeadNode == nullptr)
    {
      mHeadNode = new Node(n);
    }
    else
    {
      unsigned int levelCounter = 1;
      SaveNode(mHeadNode, n, levelCounter);

      if (n > mHeadNode->n)
      {
        if (levelCounter > mCountGreatestNumbers)
        {
          mCountGreatestNumbers = levelCounter;
        }
      }
      else
      {
        if (levelCounter > mCountLowestNumbers)
        {
          mCountLowestNumbers = levelCounter;
        }
      }
    }

    // Increase total number count
    ++mCount;

    // Evaluate if the Tree is balanced
    if ((mCountGreatestNumbers - mCountLowestNumbers) == 2 || (mCountLowestNumbers - mCountGreatestNumbers) == 2)
    {
      std::cout << "A call to ProcessVerticalBalance will be trigger,";
      std::cout << "but when be coded :) . \n Still as homework and inProgress . . .\n\n";

      ProcessVerticalBalance(); // Working Progress . . .
    }
    else
    {
      std::cout << "If a don't mistake in the previous check, so the tree is balanced . . .\n\n";
    }
  }
  catch(std::runtime_error& e)
  {
    std::cout << "Exception Catched . . . \n";
    std::cout << "Trying to save a Node \n";
  }
}

void BinaryTree::SaveNode(Node* node, const int n, unsigned int& level)
{
  if (n > node->n)
  {
    if (node->mGreater == nullptr)
    {
      node->mGreater = new Node(n);
    }
    else
    {
      ++level;
      SaveNode(node->mGreater, n, level);
    }
  }
  else
  {
    if (node->mLower == nullptr)
    {
      node->mLower = new Node(n);
    }
    else
    {
      ++level;
      SaveNode(node->mLower, n, level);
    }
  }
}


// Starts Vertical Balance Methods
void BinaryTree::ProcessVerticalBalance() // Working Progress . . .
{
  Node* tmpAverageNode = GetAverageNode();

  std::cout << "The Average selected Node is : " << tmpAverageNode->n << "\n";
}

void BinaryTree::MakeVerticalChanges(Node* node) // Working Progress . . .
{
}

Node* BinaryTree::GetAverageNode() // Working Progress . . .
{
  unsigned int total = 0;

  // This is not working as he should. Must Fix
  CalculateTotalNodesValues(mHeadNode, total);

  std::cout << "The Total sum of Nodes values is : " << total << "\n";

  // We need to return the average Node to
  // start evaluate nodes and fix the balance
  return mHeadNode; // This is momentary
}

void BinaryTree::CalculateTotalNodesValues(Node* node, unsigned int& total) // Working Progress . . .
{
  // Adding node->n values to total
  total += node->n;

  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      CalculateTotalNodesValues(node->mLower, total);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      CalculateTotalNodesValues(node->mLower, total);
    }
    node->mRightDirectionTaken = true;
  }
    node->mLeftDirectionTaken = false;
    node->mRightDirectionTaken = false;
}
// End Vertical Balance Methods

void BinaryTree::ReleaseNodes() // Working Progress . . .
{
}
