#ifndef SINGLE_TURN_CONVERSATION_SRC_ENCODER_DECODER_MODEL_PARAMS_H
#define SINGLE_TURN_CONVERSATION_SRC_ENCODER_DECODER_MODEL_PARAMS_H

#include <fstream>
#include <iostream>

#include "N3LDG.h"

struct ModelParams : public N3LDGSerializable, public TunableCombination<BaseParam>
#if USE_GPU
, public TransferableComponents
#endif
{
    LookupTable<Param> lookup_table;
    UniParams hidden_to_wordvector_params;
    UniParams hidden_to_keyword_params;
    UniParams hidden_to_bow_params;
    LSTM1Params left_to_right_encoder_params;
    AdditiveAttentionParams attention_params;

    ModelParams() : hidden_to_wordvector_params("hidden_to_wordvector_params"),
    hidden_to_keyword_params("hidden_to_keyword_params"),
    hidden_to_bow_params("hidden_to_bow_params") , left_to_right_encoder_params("lstm"),
    attention_params("attention") {}

    Json::Value toJson() const override {
        Json::Value json;
        json["lookup_table"] = lookup_table.toJson();
        json["hidden_to_wordvector_params"] = hidden_to_wordvector_params.toJson();
        json["hidden_to_keyword_params"] = hidden_to_keyword_params.toJson();
        json["hidden_to_bow_params"] = hidden_to_bow_params.toJson();
        json["left_to_right_encoder_params"] = left_to_right_encoder_params.toJson();
        json["attention_params"] = attention_params.toJson();
        return json;
    }

    void fromJson(const Json::Value &json) override {
        lookup_table.fromJson(json["lookup_table"]);
        hidden_to_wordvector_params.fromJson(json["hidden_to_wordvector_params"]);
        hidden_to_keyword_params.fromJson(json["hidden_to_keyword_params"]);
        hidden_to_bow_params.fromJson(json["hidden_to_bow_params"]);
        left_to_right_encoder_params.fromJson(json["left_to_right_encoder_params"]);
        attention_params.fromJson(json["attention_params"]);
    }

#if USE_GPU
    std::vector<n3ldg_cuda::Transferable *> transferablePtrs() override {
        return {&lookup_table, &hidden_to_wordvector_params, &hidden_to_keyword_params,
            &hidden_to_bow_params, &left_to_right_encoder_params, &attention_params};
    }
#endif

protected:
    virtual std::vector<Tunable<BaseParam> *> tunableComponents() override {
        return {&lookup_table, &hidden_to_wordvector_params, &hidden_to_keyword_params,
            &hidden_to_bow_params, &left_to_right_encoder_params, &attention_params};
    }
};

#endif
