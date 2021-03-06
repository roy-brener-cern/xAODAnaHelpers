/************************************
 *
 * Debug tool
 *
 * J.Alison (john.alison@cern.ch)
 *
 ************************************/

// c++ include(s):
#include <iostream>
#include <typeinfo>
#include <sstream>

// EL include(s):
#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>

// EDM include(s):
//#include "PATInterfaces/SystematicVariation.h"
//#include "PATInterfaces/SystematicRegistry.h"
//#include "PATInterfaces/SystematicCode.h"

// package include(s):
//#include "xAODEventInfo/EventInfo.h"
#include "xAODAnaHelpers/DebugTool.h"
#include "xAODAnaHelpers/HelperClasses.h"
#include "xAODAnaHelpers/HelperFunctions.h"

// external tools include(s):

// ROOT include(s):
#include "TFile.h"

// this is needed to distribute the algorithm to the workers
ClassImp(DebugTool)


DebugTool :: DebugTool () :
    Algorithm("DebugTool")
{
}

EL::StatusCode DebugTool :: setupJob (EL::Job& job)
{
  ANA_MSG_INFO( "Calling setupJob");
  job.useXAOD ();
  xAOD::Init( "DebugTool" ).ignore(); // call before opening first file
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: histInitialize ()
{
  ANA_MSG_INFO( "Calling histInitialize");
  ANA_CHECK( xAH::Algorithm::algInitialize());

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: fileExecute ()
{
  ANA_MSG_INFO( "Calling fileExecute");
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: changeInput (bool /*firstFile*/)
{
  ANA_MSG_INFO( "Calling changeInput");
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: initialize ()
{
  ANA_MSG_INFO( " ");

  m_event = wk()->xaodEvent();
  m_store = wk()->xaodStore();

  ANA_MSG_INFO( "Number of events in file: " << m_event->getEntries() );

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: execute ()
{
  ANA_MSG_INFO( m_name);

  //
  // look what we have in TStore
  //
  if ( m_printStore ) {
    m_store->print();
  }

  return EL::StatusCode::SUCCESS;

}


EL::StatusCode DebugTool :: postExecute ()
{
  ANA_MSG_DEBUG("Calling postExecute");
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: finalize ()
{
  ANA_MSG_INFO( m_name );
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode DebugTool :: histFinalize ()
{
  ANA_MSG_INFO( "Calling histFinalize");
  ANA_CHECK( xAH::Algorithm::algFinalize());
  return EL::StatusCode::SUCCESS;
}



