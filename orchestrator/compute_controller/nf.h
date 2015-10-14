#ifndef NF_H_
#define NF_H_ 1

#pragma once

#include <string>
#include <assert.h>
#include <list>

#include "../utils/constants.h"
#include "implementation.h"
#include "nfs_manager.h"

using namespace std;

class NF
{
private:
	/**
	*	@brief: name of the NF. This should be unique
	*/
	string name;
	
#ifdef UNIFY_NFFG
	/**
	*	@brief: number of ports of a NF
	*/
	unsigned int numPorts;
	
	/**
	*	@brief: text describing the NF
	*/
	string description;
#endif
	
	/**
	*	@brief: available implementations of the NF
	*/
	list<Implementation*> implementations;
	
	/**
	*	@brief: selected implementation for the NF
	*/
	NFsManager *selectedImplementation;	
		
	/**
	*	@brief: true if the network function is running, false otherwise
	*/
	bool isRunning;
	
public:
#ifdef UNIFY_NFFG
	NF(string name, unsigned int numPorts, string description);
#else
	NF(string name);
#endif
	
	void addImplementation(Implementation *implementation);
	list<Implementation*> getAvailableImplementations();
	
	void setSelectedImplementation(NFsManager *impl);
	NFsManager *getSelectedImplementation();
	
	void setRunning(bool val);
	bool getRunning();
	
	string getName();
	
#ifdef UNIFY_NFFG
	unsigned int getNumPorts();
	string getDescription();
#endif	
};

#endif //NF_H_ 1
