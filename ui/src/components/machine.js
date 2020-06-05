import React, { Component } from 'react'

class Machine extends Component {
  constructor(props) {
    super(props);
    this.state = {
      state: null,
    };
  }

  componentDidMount() {
    this.fetch_data();
  }

  componentWillUnmount() {
    clearInterval(this.timer)
  }

  fetch_data() {
    fetch('http://localhost:8011/machine/state', { method: 'GET' })
      .then(res => res.json())
      .then((ms) => {
        this.setState({
          state: ms.state,
        })
      })
      .catch(console.log)
  }

  handle_action(action) {
    fetch('http://localhost:8011/machine/' + action, { method: 'POST' })
      .then(this.fetch_data())
      .catch(console.log)
  }

  machine_state() {
    return 'machine-' + this.state.state
  }

  render_button() {
    return (
      <button onClick={() => this.handle_action('start')}>start</button>
    )
  }

  render() {
    return (
      <React.Fragment>
        <div className="content-box">
          <h1>Machine</h1>
        </div>
        <div className="content-box">
          <table>
            <tr>
              <td>State:</td>
              <td className={this.machine_state()}>{this.state.state}</td>
            </tr>
          </table>
        </div>
        <div className="content-box">
          {this.render_button()}
        </div>
      </React.Fragment>
    )
  }

}

export default Machine
