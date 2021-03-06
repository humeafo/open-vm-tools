/*
 *  Created on: Aug 16, 2012
 *      Author: mdonahue
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 */

#ifndef CProtocolHeaderEnricherInstance_h
#define CProtocolHeaderEnricherInstance_h



#include "Integration/IIntegrationComponentInstance.h"

#include "Common/IAppContext.h"
#include "Doc/CafCoreTypesDoc/CProtocolDoc.h"
#include "Doc/PayloadEnvelopeDoc/CPayloadEnvelopeDoc.h"
#include "Integration/IChannelResolver.h"
#include "Integration/IDocument.h"
#include "Integration/IIntMessage.h"
#include "Integration/IIntegrationObject.h"
#include "Integration/ITransformer.h"

namespace Caf {

class CProtocolHeaderEnricherInstance :
	public TCafSubSystemObjectRoot<CProtocolHeaderEnricherInstance>,
	public IIntegrationObject,
	public IIntegrationComponentInstance,
	public ITransformer {
public:
	CProtocolHeaderEnricherInstance();
	virtual ~CProtocolHeaderEnricherInstance();

	CAF_DECLARE_OBJECT_IDENTIFIER(_sObjIdCommIntegrationProtocolHeaderEnricherInstance)

	CAF_BEGIN_INTERFACE_MAP(CProtocolHeaderEnricherInstance)
		CAF_INTERFACE_ENTRY(IIntegrationObject)
		CAF_INTERFACE_ENTRY(IIntegrationComponentInstance)
		CAF_INTERFACE_ENTRY(ITransformer)
	CAF_END_INTERFACE_MAP()

public: // IIntegrationObject
	void initialize(
		const IBean::Cargs& ctorArgs,
		const IBean::Cprops& properties,
		const SmartPtrIDocument& configSection);

	std::string getId() const;

public: // IIntegrationComponentInstance
	void wire(
		const SmartPtrIAppContext& appContext,
		const SmartPtrIChannelResolver& channelResolver);

public: // ITransformer
	SmartPtrIIntMessage transformMessage(
		const SmartPtrIIntMessage& message);

private:
	SmartPtrCProtocolDoc findProtocol(
			const SmartPtrCPayloadEnvelopeDoc& payloadEnvelope) const;

private:
	bool _isInitialized;
	std::string _id;

private:
	CAF_CM_CREATE;
	CAF_CM_CREATE_LOG;
	CAF_CM_DECLARE_NOCOPY(CProtocolHeaderEnricherInstance);
};

}

#endif /* CProtocolHeaderEnricherInstance_h */
