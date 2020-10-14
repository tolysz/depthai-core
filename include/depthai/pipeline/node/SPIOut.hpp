#pragma once

#include <depthai/pipeline/Node.hpp>

// shared
#include <depthai-shared/pb/properties/SPIOutProperties.hpp>

namespace dai
{
    namespace node
    {
        class SPIOut : public Node {
            dai::SPIOutProperties properties;
        
            std::string getName(){
                return "SPIOut";
            }
        
            std::vector<Input> getInputs(){
                return {in};
            }
            
            std::vector<Output> getOutputs(){
                return {};
            }

            nlohmann::json getProperties(){
                nlohmann::json j;
                nlohmann::to_json(j, properties);
                return j;
            }

            std::shared_ptr<Node> clone(){
                return std::make_shared<SPIOut>(*this);
            }
        
        public:
            SPIOut(const std::shared_ptr<PipelineImpl>& par) : Node(par) {
            }

            Input in{*this, "in", Input::Type::SReceiver, {{DatatypeEnum::RawBuffer, true}} };

            void setStreamName(std::string name){
                properties.streamName = name;
            }

        };

    } // namespace node
} // namespace dai
