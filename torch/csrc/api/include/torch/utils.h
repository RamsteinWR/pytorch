#pragma once

#include <ATen/Parallel.h>
#include <torch/csrc/autograd/grad_mode.h>

#include <cstdint>

namespace torch {
using autograd::AutoGradMode;

// A RAII, thread local (!) guard that stops future operations from building
// gradients.
struct TORCH_API NoGradGuard : public AutoGradMode {
  NoGradGuard() : AutoGradMode(/*enabled=*/false) {}
};

/// Sets the global random seed for all newly created CPU and CUDA tensors.
using at::manual_seed;

// Called during new thread initialization
using at::init_num_threads;

// Returns the number of threads used in parallel region.
using at::get_num_threads;

// Sets the number of threads to be used in parallel region.
using at::set_num_threads;

} // namespace torch
