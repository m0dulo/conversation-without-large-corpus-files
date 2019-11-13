#ifndef SINGLE_TURN_CONVERSATION_PERPLEX_H
#define SINGLE_TURN_CONVERSATION_PERPLEX_H

#include <memory>
#include <tuple>
#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
#include <boost/format.hpp>

#include "N3LDG.h"

dtype computePerplex(const std::vector<Node *> &nodes, const std::vector<int> &answers, int len) {
    dtype log_sum = 0.0f;

    for (int i = 0; i < nodes.size(); ++i) {
        Node &node = *nodes.at(i);
        dtype reciprocal_answer_prob = 1 / node.getVal().v[answers.at(i)];
        log_sum += log(reciprocal_answer_prob);
    }

    return exp(1.0f / len * log_sum);
}

#endif
