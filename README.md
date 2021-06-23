# Avalon demo

Simple [Avalon](https://github.com/hyperledger/avalon) workload for determining whether an input number is odd or even.

## Avalon Deployment

You can deploy Avalon using:

* [Docker](https://github.com/hyperledger/avalon/blob/master/BUILD.md#dockerbuild)
* [Standalone Build](https://github.com/hyperledger/avalon/blob/master/BUILD.md#standalonebuild)

## Workload installation

1. Clone this repository into `$TCF_HOME/examples/apps/lukask_parity`
2. Add this line to the end of `$TCF_HOME/examples/apps/CMakeLists.txt`:

    ```
    ADD_SUBDIRECTORY(lukask_parity/workload)
    ```

3. Add workload to supported workload list in `$TCF_HOME/tc/sgx/trusted_worker_manager/enclave/CMakeWorkloads.txt`:

    ```
    LIST(APPEND SUPPORTED_WORKLOADS_LIST "lukask-parity")
    ```

4. Add workload static library to supported workload library list in `$TCF_HOME/tc/sgx/trusted_worker_manager/enclave/CMakeWorkloads.txt`:

    ```
    LIST(APPEND SUPPORTED_WORKLOAD_LIBRARY_LIST "lukask_parity")
    ```

5. Rebuild Avalon (for Docker: `docker-compose up -d --build`)

## Workload usage

You can use this workload via generic client shipped with Avalon (use `avalon-shell` container if using Docker):

```bash
./generic_client.py -o --uri "http://avalon-listener:1947" --workload_id "lukask-parity" --in_data "<NUMBER>" --worker_id "singleton-worker-1"
```