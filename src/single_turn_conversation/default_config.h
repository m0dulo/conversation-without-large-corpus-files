#ifndef SINGLE_TURN_CONVERSATION_DEFAULT_CONFIG_H
#define SINGLE_TURN_CONVERSATION_DEFAULT_CONFIG_H

#include <iostream>
#include <string>

enum ProgramMode {
    TRAINING = 0,
    DECODING = 1,
    INTERACTING = 2,
    METRIC = 3,
};

struct NgramPenalty {
    float one;
    float two;
    float three;
};

struct DefaultConfig {
    std::string pair_file;
    std::string post_file;
    std::string response_file;
    ProgramMode program_mode;
    bool check_grad;
    bool one_response;
    bool learn_test;
    bool save_model_per_batch;
    bool split_unknown_words;
    int max_sample_count;
    int dev_size;
    int test_size;
    int device_id;
    int hold_batch_size;
    int seed;
    int cut_length;
    std::string output_model_file_prefix;
    std::string input_model_file;
    std::string input_model_dir;
    std::string black_list_file;
    float memory_in_gb;
    float ngram_penalty_1;
    float ngram_penalty_2;
    float ngram_penalty_3;
    float result_count_factor;

    NgramPenalty toNgramPenalty() const {
        return {ngram_penalty_1, ngram_penalty_2, ngram_penalty_3};
    }

    void print() const {
        std::cout << "pair_file:" << pair_file << std::endl
            << "post_file:" << post_file << std::endl
            << "response_file:" << response_file << std::endl
            << "program_mode:" << program_mode << std::endl
            << "check_grad:" << check_grad << std::endl
            << "one_response:" << one_response << std::endl
            << "learn_test:" << learn_test << std::endl
            << "save_model_per_batch:" << save_model_per_batch << std::endl
            << "split_unknown_words:" << split_unknown_words << std::endl
            << "max_sample_count:" << max_sample_count << std::endl
            << "dev_size:" << dev_size << std::endl
            << "test_size:" << test_size << std::endl
            << "device_id:" << device_id << std::endl
            << "hold_batch_size:" << hold_batch_size << std::endl
            << "seed:" << seed << std::endl
            << "cut_length:" << cut_length << std::endl
            << "output_model_file_prefix" << output_model_file_prefix << std::endl
            << "input_model_file:" << input_model_file << std::endl
            << "input_model_dir:" << input_model_dir << std::endl
            << "black_list_file:" << black_list_file << std::endl
            << "memory_in_gb:" << memory_in_gb << std::endl
            << "ngram_penalty_1:" << ngram_penalty_1 << std::endl
            << "ngram_penalty_2:" << ngram_penalty_2 << std::endl
            << "ngram_penalty_3:" << ngram_penalty_3 << std::endl
            << "result_count_factor:" << result_count_factor << std::endl;
    }
};

DefaultConfig &GetDefaultConfig() {
    static DefaultConfig default_config;
    return default_config;
}

#endif
