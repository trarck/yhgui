#ifndef COCOS_YHGUI_YHGUI_H_
#define COCOS_YHGUI_YHGUI_H_

#include "YHGUIMacros.h"
#include "Component.h"
#include "Container.h"

#include "event/UIEventNames.h"
#include "event/UIEventListenerManager.h"

#include "utils/Utils.h"

#include "control/Button.h"
#include "control/NormalButton.h"
#include "control/ComplexButton.h"

//交互项
#include "interactive/Organizer.h"
#include "interactive/DocumentTreeOrganizer.h"
#include "interactive/NormalDocumentTreeOrganizer.h"
#include "interactive/ListOrganizer.h"
#include "interactive/OrderedListOrganizer.h"
#include "interactive/PriorityOrganizer.h"
#include "interactive/IndependentDocumentTreeOrganizer.h"
#include "interactive/IndependentNormalDocumentTreeOrganizer.h"
#include "interactive/IndependentListOrganizer.h"
#include "interactive/IndependentOrderedListOrganizer.h"
#include "interactive/IndependentPriorityOrganizer.h"

//builder
#include "builder/UIBuilderMacros.h"
#include "builder/UIBuilderConsts.h"
#include "builder/ElementCreator.h"
#include "builder/ElementParser.h"
#include "builder/element_parsers/ComponentialElementParser.h"
#include "builder/element_parsers/NodeParser.h"
#include "builder/property_parsers/NodePropertyParser.h"
#include "builder/property_parsers/LabelPropertyParser.h"
#include "builder/PropertyParserCompiler.h"
#include "builder/ElementCreatorFactory.h"
#include "builder/ElementParserFactory.h"
#include "builder/ElementEventParser.h"
#include "builder/UIBuilder.h"

#endif //COCOS_YHGUI_YHGUI_H_