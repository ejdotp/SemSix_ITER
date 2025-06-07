# 🛡️ Image Encryption and Decryption using DES

## 📌 Project Overview
This project explores the implementation of **image encryption and decryption** using the **Data Encryption Standard (DES)**, a symmetric-key cryptographic algorithm. It demonstrates how DES can secure image data during transmission and storage by transforming it into an unreadable format and later reconstructing the original image using the same secret key.

---

## 🎯 Objectives

- To study and understand the DES (Data Encryption Standard) algorithm and its applicability to image encryption.
- To develop a Python-based system that encrypts and decrypts image files using DES.
- To preserve the original image quality and resolution after decryption.
- To validate the encryption/decryption process using image quality and hash metrics.
- To measure performance in terms of encryption and decryption speed.
- To assess the reliability of DES for secure image communication.

---

## 🔧 Tools and Technologies

- **Language:** Python 3.x  
- **IDE:** Jupyter Notebook (via Anaconda)  
- **Libraries:**  
  - `Pillow` for image processing  
  - `PyCryptodome` for cryptography  
  - `NumPy` for numerical operations  
  - `Matplotlib` for visual display  
  - `time`, `hashlib` for performance and integrity validation

---

## 🔬 Methodology

### 1. Image Input and Preprocessing
- The input image is loaded using Pillow and converted to grayscale.
- The pixel matrix is flattened into a byte stream using NumPy.

### 2. Byte Stream Preparation
- The byte stream is padded (if needed) to ensure its length is a multiple of 8 bytes (64 bits), as required by DES.

### 3. Key Generation
- A **64-bit symmetric key** is randomly generated using `Crypto.Random`.
- The same key is used for both encryption and decryption.

### 4. DES Encryption
- The byte stream is encrypted using DES in **ECB (Electronic Codebook)** mode.
- Encrypted blocks are combined to form the full encrypted image byte stream.

### 5. Encrypted Image Reconstruction
- The encrypted byte stream is reshaped to the original image dimensions.
- The encrypted image is displayed and saved; it appears as unintelligible noise.

### 6. DES Decryption
- The encrypted image is converted back to a byte stream.
- Each block is decrypted using the same key and reshaped into an image.

### 7. Output and Integrity Validation
- The decrypted image is compared visually and pixel-wise with the original.
- Evaluation Metrics:
  - **Exact match** using `np.array_equal()`
  - **Mean Squared Error (MSE)**
  - **SHA-256 hash** of byte arrays

### 8. Performance Evaluation
- **Execution times** for encryption and decryption are measured.
- The algorithm is observed to perform efficiently for grayscale images.

---

## 📈 Results Summary

| Metric              | Value (Example)              |
|---------------------|------------------------------|
| MSE                 | 0.0000 (exact match)         |
| Hash Match          | ✅ Yes                       |
| Execution Time (Enc)| ~0.012 seconds               |
| Execution Time (Dec)| ~0.010 seconds               |

> Note: Results may vary depending on image size and system performance.

---

## ✅ Conclusion

This project confirms that DES, despite being outdated for modern security standards, effectively encrypts and decrypts image data for educational or low-risk use cases. The encrypted image is unreadable without the correct key, and the decrypted output closely matches the original with no visual or statistical degradation.

---