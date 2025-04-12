#include <iostream>
#include <vector>
#include <cmath>

int closest_in_scale(int midi_note, const std::vector<int>& scale) {
    int left = 0;
    int right = scale.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (scale[mid] == midi_note) {
            return midi_note;
        } else if (scale[mid] < midi_note) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    int higher = (left < scale.size()) ? scale[left] : INT_MAX;
    int lower = (left > 0) ? scale[left - 1] : INT_MIN;

    if (std::abs(higher - midi_note) < std::abs(lower - midi_note)) {
        return higher;
    } else {
        return lower;
    }
}

std::vector<int> quantize(std::vector<double>& frequencies, std::vector<int>& scale) {
    std::vector<int> result;
    for (double f : frequencies) {
        double midi_float = 69.0 + 12.0 * std::log2(f / 440.0);
        int midi = static_cast<int>(std::round(midi_float));
        int quantized = closest_in_scale(midi, scale);
        result.push_back(quantized);
    }

    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<double> frequencies(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> frequencies[i];
    }

    std::vector<int> scale(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> scale[i];
    }

    for (int i : quantize(frequencies, scale)) {
        std::cout << i << " ";
    }

    return 0;
}